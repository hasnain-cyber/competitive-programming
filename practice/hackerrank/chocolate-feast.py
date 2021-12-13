for _ in range(int(input())):
    money, cost, m = list(map(int, input().split()))

    total = money // cost
    wrappers = money // cost
    extras = 0
    while True:
        if wrappers // m == 0:
            break
        extras = wrappers // m
        total += extras
        wrappers = wrappers - extras * m + extras
    print(total)

# correct
