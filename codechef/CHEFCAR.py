for _ in range(int(input())):
    n, v = tuple(map(int, input().split()))

    maxCost = n * (n - 1) // 2
    if v >= n - 1:
        minCost = n - 1
    else:
        k = n - v
        minCost = v - 1 + k * (k + 1) // 2
    print(maxCost, minCost)

# correct
