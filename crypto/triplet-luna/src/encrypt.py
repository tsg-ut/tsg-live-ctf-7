from secret import flag
from Crypto.Util.number import getStrongPrime, isPrime

assert(type(flag) == bytes)
assert(len(flag) < 65)

flag_int = int.from_bytes(flag, "big")

p = getStrongPrime(1024)
q = getStrongPrime(1024)
r = getStrongPrime(1024)
s = getStrongPrime(1024)
t = getStrongPrime(1024)
u = getStrongPrime(1024)

N1 = p * q * r
N2 = s * t * u
phi1 = (p - 1) * (q - 1) * (r - 1)
phi2 = (s - 1) * (t - 1) * (u - 1)
e = 11
d1 = pow(e, -1, phi1)
d2 = pow(e, -1, phi2)

enc1 = pow(flag_int, e, N1)
enc2 = pow(flag_int, e, N2)

with open("./enc.txt", 'w') as f:
    print(N1,e,enc1,file = f)
    print(N2,e,enc2,file = f)

dec1 = pow(enc1, d1, N1)
dec2 = pow(enc2, d2, N2)

assert(flag_int == dec1)
assert(flag_int == dec2)
