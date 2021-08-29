for _ in range(int(input())):
    n, k, s = list(map(int, input().split()))
    print((s - n ** 2) // (k - 1))

# correct
