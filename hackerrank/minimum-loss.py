length = int(input())
arr = list(map(int, input().split()))
sortedArr = sorted(arr, reverse=True)

minLoss = -1
for i in range(length - 1):
    loss = sortedArr[i] - sortedArr[i + 1]
    if (loss < minLoss or minLoss == -1) and arr.index(sortedArr[i + 1]) > arr.index(sortedArr[i]):
        minLoss = loss
print(minLoss)

# correct
