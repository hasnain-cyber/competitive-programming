for _ in range(int(input())):
    length = int(input())
    arr = list(map(int, input().split()))
    arr.reverse()

    if max(arr) != arr[-1]:
        print(-1)
    else:
        currentHeight = arr[0]
        counter = 0
        for height in arr:
            if height > currentHeight:
                counter += 1
                currentHeight = height
        print(max(counter, 1))


# wrong answer
