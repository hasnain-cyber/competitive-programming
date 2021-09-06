for _ in range(int(input())):
    string = input()
    length = len(string)

    countDict = dict()
    counter = 0
    for i in range(length):
        for j in range(i, length):
            sortedSubString = str(sorted(string[i: j + 1]))
            if sortedSubString in countDict:
                counter += countDict[sortedSubString]
                countDict[sortedSubString] += 1
            else:
                countDict[sortedSubString] = 1
    print(counter)

# correct
