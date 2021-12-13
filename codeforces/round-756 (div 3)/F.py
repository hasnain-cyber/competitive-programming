for _ in range(int(input())):
    n, totalRubles = tuple(map(int, input().split()))
    arr = list(map(int, input().split()))

    maxTuple = None
    startIndex = 0
    remainingRubles = totalRubles
    for endIndex in range(len(arr)):
        remainingRubles += arr[endIndex]

        if remainingRubles < 0:
            startIndex = endIndex + 1
            endIndex = startIndex
            remainingRubles = totalRubles
        else:
            if maxTuple is None or endIndex - startIndex > maxTuple[1] - maxTuple[0]:
                maxTuple = (startIndex, endIndex)

    if maxTuple:
        print(maxTuple[0] + 1, maxTuple[1] + 1)
    else:
        print(-1)

# wrong answer
