for _ in range(int(input())):
    n = int(input())
    arr = [1, 1]
    for i in range(1, n):
        arr.append(2**i)
    print(*arr)

# correct answer