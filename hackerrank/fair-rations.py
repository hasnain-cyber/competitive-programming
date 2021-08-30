n = int(input())
arr = list(map(int, input().split()))

tempCounter = 1
totalCounter = 0
while tempCounter > 0:
    tempCounter = 0
    for i in range(n - 1):
        if not arr[i] % 2 == 0:
            arr[i] += 1
            arr[i + 1] += 1
            totalCounter += 2
            tempCounter += 1

flag = True
for element in arr:
    if not element % 2 == 0:
        flag = False
        break
if not flag:
    print('NO')
else:
    print(totalCounter)

# correct
