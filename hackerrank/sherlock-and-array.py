for _ in range(int(input())):
    length = int(input())
    arr = list(map(int, input().split()))

    totalSum = sum(arr)
    leftSum = 0
    flag = False
    for element in arr:
        rightSum = totalSum - leftSum - element
        if rightSum == leftSum:
            flag = True
            break
        leftSum += element
    if flag:
        print('YES')
    else:
        print('NO')

# correct
