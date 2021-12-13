length = int(input())
arr = list(map(int, input().split()))
arr.sort()

minDifference = abs(arr[1] - arr[0])
for i in range(1, length - 1):
    difference = abs(arr[i + 1] - arr[i])
    if difference < minDifference:
        minDifference = difference

outputArr = []
for i in range(length - 1):
    for j in range(i + 1, length):
        difference = abs(arr[j] - arr[i])
        if difference == minDifference:
            outputArr.append(arr[i])
            outputArr.append(arr[j])
        else:
            break

print(*outputArr)

# correct
