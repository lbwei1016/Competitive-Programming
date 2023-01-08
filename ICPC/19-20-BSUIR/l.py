from sys import stdin, stdout
MOD = 10**9 + 7
# x, q = input(), int(input())
buffer = stdin.read().split('\n')
# print(buffer)
x, q = buffer[0], int(buffer[1])
# print(x)
val = int(x) % MOD
# x = [0] * 
x = [i for i in x]

# if not x[-1] in [0,1,2,3,4,5,6,7,8,9]:
#     x.pop()
    
# print(x)
# print(x)

bufcnt = 2
out = [''] * q
cnt = 0

# x %= MOD
for i in range(q):
    # inp = input()
    inp = buffer[bufcnt]
    bufcnt += 1
    c = inp[0]
    # print("i: ", i)
    if c == '+':
        y = eval(inp[2])
        val *= 10
        val += y
        val %= MOD
        x.append(y)
    else:
        # print("x[-1]: ", x[-1])
        y = int(x[-1])
        x.pop()
        val -= y
        val *= 700000005 # divide by 10
        val %= MOD
        val += MOD
        val %= MOD
    out[cnt] = str(val)
    cnt += 1
    # print(val)
# print(type(out))
stdout.write('\n'.join(out))
