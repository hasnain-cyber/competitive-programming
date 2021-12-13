for _ in range(int(input())):
    n, s = tuple(map(int, input().split()))
    totalSum = (n * (n + 1)) // 2

    answer = totalSum - s
    if 0 < answer <= n:
        print(answer)
    else:
        print(-1)

# correct
