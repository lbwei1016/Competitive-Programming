from cmath import log10
from math import ceil, floor


S = input()

def solve():
    dig = 1000
    if (S[0] == '0'):
        print(1)
        return
    dig = min(dig, len(S))
    val6, cnt = 0, 1
    for i in range(dig):
        val6 += (eval(S[i])) * cnt
        cnt /= 10.0

    lg6 = log10(val6).real
    # print("lg6:", lg6)
    res = ((len(S) - 1 + lg6) / log10(6)).real

    # print("res", res)
    # ans = ceil(res)
    ans = floor(res)

    N = 6 ** ans
    # print("N:", N)
    # print("ans:", ans)
    SN = eval(S)
    if SN >= N:
        ans += 1
    # elif N > SN:
        # ans -= 1
    print(ans)


solve()