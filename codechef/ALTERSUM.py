for _ in range(int(input())):
    length = int(input())
    arr = list(map(int, input().split()))

    prefixSumArr = [0]
    for i in range(length - 1):
        if i % 2 == 0:
            prefixSumArr.append(prefixSumArr[-1] + arr[i])
        else:
            prefixSumArr.append(prefixSumArr[-1] - arr[i])

    totalSum = prefixSumArr[-1] - arr[-1] if len(arr) % 2 == 0 else prefixSumArr[-1] + arr[-1]
    maxSum = totalSum
    for i in range(0, len(arr)):
        for j in range(i, len(arr) - 1, 2):
            currentSum = -totalSum + prefixSumArr[i] + prefixSumArr[j + 1]
            if (length - j) % 2 == 0:
                currentSum -= prefixSumArr[j + 1] - prefixSumArr[i]
            else:
                currentSum += prefixSumArr[j + 1] - prefixSumArr[i]
            if currentSum > maxSum:
                maxSum = currentSum
    print(maxSum)

# tle
