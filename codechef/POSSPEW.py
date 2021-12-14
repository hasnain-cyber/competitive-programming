for _ in range(int(input())):
    n, k = tuple(map(int, input().split()))
    arr = list(map(int, input().split()))

    posIndices = set()
    for index, value in enumerate(arr):
        if value > 0:
            posIndices.add(index)

    for t in range(k):
        markArr = list()
        for index in posIndices:
            if index == n - 1:
                markArr.append(0)
                markArr.append(n - 2)
            elif index == 0:
                markArr.append(n - 1)
                markArr.append(1)
            else:
                markArr.append(index + 1)
                markArr.append(index - 1)
        for index in markArr:
            if arr[index] == 0:
                posIndices.add(index)
            arr[index] += 1
    print(sum(arr))

# tle
