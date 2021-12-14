for _ in range(int(input())):
    n, k = tuple(map(int, input().split()))
    arr = list(map(int, input().split()))

    maxValue = max(arr)
    maxIndices = []
    for i, element in enumerate(arr):
        if element == maxValue:
            maxIndices.append(i)

    counter = 0
    for index in maxIndices:
        if index + 1 < k:
            continue
        else:
            counter += n - index
    print(counter)

# correct
