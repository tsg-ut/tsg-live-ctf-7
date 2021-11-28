from math import gcd
from sympy.ntheory.modular import crt

N1, e, enc1 = map(int, input().split())
N2, e, enc2 = map(int, input().split())

g = gcd(N1, N2)
p = N1 // g
s = N2 // g

e1 = enc1 % p
e2 = enc2 % s

d1 = pow(e, -1, p-1)
d2 = pow(e, -1, s-1)

dec1 = pow(e1, d1, p)
dec2 = pow(e2, d2, s)

dec, N = crt([p, s], [dec1, dec2])
dec = int(dec)

print(dec, N)

print(dec.to_bytes(240, 'big'))
