for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))

    if n == arr[0]:
        printArr = arr[1:]
        printArr.reverse()
        printArr.append(n)
        print(*printArr)
    elif n == arr[-1]:
        printArr = arr[:n - 1]
        printArr.reverse()
        printArr.append(n)
        print(*printArr)
    else:
        print(-1)
