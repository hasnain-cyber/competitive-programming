for _ in range(int(input())):
    n, s = tuple(map(int, input().split()))
    if n >= s:
        print(s)
    else:
        print(2 * n - s)

# correct
