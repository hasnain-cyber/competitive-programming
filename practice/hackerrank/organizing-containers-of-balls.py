for _ in range(int(input())):
    length = int(input())

    countArray = [0 for i in range(length)]
    capacityArray = []
    for t in range(length):
        tempList = list(map(int, input().split()))
        capacityArray.append(sum(tempList))
        for i in range(length):
            countArray[i] += tempList[i]

    countArray.sort()
    capacityArray.sort()
    if countArray == capacityArray:
        print('Possible')
    else:
        print('Impossible')

# correct
