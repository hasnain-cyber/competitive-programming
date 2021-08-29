for _ in range(int(input())):
    n = int(input())
    heightArr = list(map(int, input().split()))
    heightArr.reverse()

    counter = 0
    currentMax = heightArr[0]
    for i in range(n):
        if heightArr[i] > currentMax:
            currentMax = heightArr[i]
            counter += 1
    if not currentMax == heightArr[-1]:
        print(-1)
    else:
        print(counter)

# wrong answer
