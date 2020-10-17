X, Y, A, B = map(int, input().split())

p = 0
ans = 0
q = 0

while True:

    q = (Y - X) // B
    if (Y - X) % B == 0:
        q -= 1

    if X + q * B >= Y or q < 0:
        break

    ans = max(ans, p + q)

    X *= A
    p += 1

print(ans)
