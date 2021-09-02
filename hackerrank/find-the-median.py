length = int(input())
arr = list(map(int, input().split()))
arr.sort()

if length % 2 == 0:
    print((arr[length // 2] + arr[length // 2 - 1]) // 2)
else:
    print(arr[(length - 1) // 2])

# correct
