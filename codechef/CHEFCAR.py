for _ in range(int(input())):
    n, v = list(map(int, input().split()))

    maxCost = n*(n-1)//2

    minCost = n-1
    if (v < n-1):
        k = n-v
        minCost = v + (k-1)*(k+2)//2

    print(maxCost, minCost)

# wrong answer