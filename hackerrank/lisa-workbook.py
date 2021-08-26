n, k = list(map(int, input().split()))
arr = list(map(int, input().split()))

page = 1
counter = 0

for i in range(len(arr)):
    counter += 1 if arr[i] <= page else 0
    page += 1

# incomplete
