def findFixedPoints(arr):
    counter = 0
    for i in range(len(arr)):
        if i+1 == arr[i]:
            counter += 1
    return counter

for _ in range(int(input())):
    length = int(input())
    arr = list(map(int, input().split()))

    counter = 0
    for i in range(length):
        for j in range(i, length):
            counter += findFixedPoints(arr[i: j+1])
    print(counter)

# tle