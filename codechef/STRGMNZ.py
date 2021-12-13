import math

for _ in range(int(input())):
    n = int(input())

    minX = n + 1
    gcd = math.gcd(minX, n)
    minValue = (minX * n - (gcd ** 2)) // gcd
    for x in range(minX + 1, 2 * n):
        gcd = math.gcd(x, n)
        value = (x * n - (gcd ** 2)) // gcd
        if value < minValue:
            value = minValue
            minX = x
    print(minX)
