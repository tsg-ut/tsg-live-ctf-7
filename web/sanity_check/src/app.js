const fs = require('fs');
const get = require('get-stream');
const fastify = require('fastify');

const flag = process.env.FLAG;
const app = fastify();

const getRandoms = async (n, count, source = 'urandom') => {
	const stream = fs.createReadStream(`/dev/${source}`, {end: count * 4});
	const data = await get(stream, {encoding: 'buffer'});
	return Array(count).fill().map((_, i) => (
		data.readUInt32BE(i * 4) % n + 1
	));
};

app.get('/', (req, res) => {
	res.type('text/html');
	return fs.readFileSync('index.html');
});

app.post('/', async (req) => {
	const {source, message} = req.body;
	if (message.length >= 7) {
		return 'Too long!';
	}
	const [count, n] = message.split('d').map(Number);
	const numbers = await getRandoms(n, count, source);
	const sum = numbers.reduce((a, b) => a + b);
	if (sum === 77777) {
		return `Jackpot!!! ${flag}`;
	}
	return numbers.join(' + ') + ' = ' + sum;
});

app.listen(14253, '0.0.0.0');
