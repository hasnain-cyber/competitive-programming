n = int(input())
arr = list(map(int, input().split()))
sortedArr = sorted(arr)
a = []
subArr = []

counter = 0
for i in range(n):
    if arr[i] != sortedArr[i]:
        counter += 1
        a.append(i + 1)
if counter == 2:
    print("yes")
    print("swap", a[0], a[1])
else:
    for i in range(n):
        if not arr[i] == sortedArr[i]:
            subArr.append(arr[i])
    if subArr == sorted(subArr, reverse=True):
        print("yes")
        print("reverse", arr.index(subArr[0]) + 1, arr.index(subArr[-1]) + 1)
    else:
        print("no")

# correct
