for _ in range(int(input())):
    totalMoney = int(input())
    length = int(input())
    costArray = list(map(int, input().split()))

    i, j = 0, 0
    breakFlag = False
    for i in range(length):
        if breakFlag:
            break
        remainingMoney = totalMoney - costArray[i]
        for j in range(length - 1, i, -1):
            if remainingMoney == costArray[j]:
                breakFlag = True
                break
    print(i, j + 1)

# correct
