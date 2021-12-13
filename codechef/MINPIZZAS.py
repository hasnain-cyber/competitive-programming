import math


def lcm(a, b):
    return abs(a * b) // math.gcd(a, b)


for _ in range(int(input())):
    n, k = tuple(map(int, input().split()))
    print(lcm(n, k) // k)

# correct
