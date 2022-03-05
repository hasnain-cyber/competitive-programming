for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    val = 0
    res = sum(a)
    total = res
    for i in range(n):
        val += a[i]
        res = min(max(val, total - val), res)
    print(res)

# correct
