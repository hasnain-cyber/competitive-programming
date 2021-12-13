for _ in range(int(input())):
    arr = list(map(int, input().split()))
    minSub = min(arr)
    if minSub == arr[0]:
        print('Draw')
    elif minSub == arr[1]:
        print('Bob')
    else:
        print('Alice')

# correct
