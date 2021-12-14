for _ in range(int(input())):
    length = int(input())
    arr = list(map(int, input().split()))

    counter = 0
    for index, value in enumerate(arr):
        if index + 1 >= value:
            counter += length - index
    print(counter)

# correct
