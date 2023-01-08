from sys import stdin, stdout
# import math
from math import log2
from math import pow
from math import sqrt

OUTSIZE = 1e5
EPS = 1e-8
inbuf = stdin.read().split(' ')
# assign first faster than .append()
# outbuf = [] * OUTSIZE
incnt, outcnt = 0, 0
# stdout.write('\n'.join(outbuf))
# stdout.write('\n'.join(map(str, outbuf)))

n, p, s, v = [float(x) for x in inbuf]
lgsdv = log2(s) - log2(v)
lglgn = log2(log2(n))
sq2 = sqrt(2)
k = log2(n) ** sq2
A = s * p * 1e9

def cal(c):
    try:
        x = k ** c * c * c
    except:
        print(k, c)
        exit(-1)
    return (x * (n * lglgn * sq2 * v) - A) > EPS

lb = 1e-6
ub = 200.000000
mn = 1e60
cc = ub
for i in range(200):
    mid = (lb + ub) * 0.5
    if (cal(mid)):
         ub = mid
    else:
         lb = mid
    if ((v * cc * mid * n * (k**cc - k**mid) - p * 1e9 * s * (cc - mid)) > EPS):
        cc = mid
print('cc: ', cc)