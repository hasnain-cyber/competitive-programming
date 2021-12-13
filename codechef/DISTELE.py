for _ in range(int(input())):
    length = int(input())
    arr = list(map(int, input().split()))

    indexDict = dict()
    counter = 0
    total = 0
    for i in range(length):
        value = arr[i]
        if value in indexDict.keys():
            total += counter * (counter + 1) // 2
            k = i - indexDict[value][-1] - 1
            indexDict[value].append(i)
            total -= k * (k + 1) // 2
            counter = k + 1
        else:
            indexDict[value] = [i]
            counter += 1
    total += counter * (counter + 1) // 2
    print(total)
