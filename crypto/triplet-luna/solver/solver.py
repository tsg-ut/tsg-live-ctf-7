from sympy.ntheory.modular import crt

def int_sqrt(x, d):
    l = 1
    r = x
    while l + 1 < r:
        mid = (l+r) // 2
        if mid ** d <= x:
            l = mid
        else:
            r = mid
    return l

N1, e, enc1 = map(int, input().split())
N2, e, enc2 = map(int, input().split())

print(int_sqrt(enc1,e).to_bytes(128, 'big'))

enc, N = crt([N1, N2], [enc1, enc2])

dec = int_sqrt(enc, e)
dec = int(dec)

print(dec.to_bytes(65, 'big'))
