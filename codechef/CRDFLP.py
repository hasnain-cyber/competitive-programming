for _ in range(int(input())):
    n = int(input())
    frontArray = list(map(int, input().split()))
    backArray = list(map(int, input().split()))

    a1, a2 = frontArray[0], backArray[0]
    counter1, counter2 = 0, 1
    for i in range(1, n):
        if a1 & frontArray[i] > a1 & backArray[i]:
            a1 = a1 & frontArray[i]
        else:
            a1 = a1 & backArray[i]
            counter1 += 1
        if a2 & frontArray[i] > a2 & backArray[i]:
            a2 = a2 & frontArray[i]
        else:
            a2 = a2 & backArray[i]
            counter2 += 1
    if a1 < a2:
        print(a2, min(n - counter2, counter2))
    else:
        print(a1, min(n - counter1, counter1))

# wrong
