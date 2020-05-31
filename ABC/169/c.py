A, B = map(float, input().split())
B *= 100
AA = int(A)
cnt = 0
while A > 0:
    A /= 10
    cnt += 1

B = B * (10 ** (cnt - 2))
print(int(A * B))
