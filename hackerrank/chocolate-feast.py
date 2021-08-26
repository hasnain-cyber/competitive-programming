for _ in range(int(input())):
    n, c, m = list(map(int, input().split()))

    total = n // c
    wrappers = n // c
    a = 0
    while True:
        a = wrappers // m
        total += a
        a = a // m + total % m
        if a == 0:
            break
    print(total)

# wrong answer