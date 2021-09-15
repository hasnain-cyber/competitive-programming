for _ in range(int(input())):
    n, s = tuple(map(int, input().split()))
    index = (n - 1) // 2
    answer = s // (n - index)
    print(answer)

# correct
