for _ in range(int(input())):
    n, k = tuple(map(int, input().split()))
    arr = list(map(int, input().split()))
    s = sum(arr)

    for i in range(k):
        for element in arr:
            if element > 0:
                s += 2
    print(s)

# tle
