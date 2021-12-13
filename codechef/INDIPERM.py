for _ in range(int(input())):
    n = int(input())

    arr = []
    for i in range(2, n + 1):
        arr.append(i)
    arr.append(1)

    print(*arr)
