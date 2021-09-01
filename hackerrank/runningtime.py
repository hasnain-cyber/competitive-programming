l = int(input())
arr = list(map(int, input().split()))

counter = 0
for i in range(1, l):
    key = arr[i]
    j = i - 1
    while j >= 0 and arr[j] > key:
        arr[j + 1] = arr[j]
        j = j - 1
        counter += 1
    arr[j + 1] = key

print(counter)

# correct
