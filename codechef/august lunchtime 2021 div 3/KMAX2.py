for _ in range(int(input())):
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    counter = 0
    maxArr = max(arr)
    for i in range(k, n):
        if arr[i] == maxArr:
            counter += n - i
    print(counter)

# wrong answer
