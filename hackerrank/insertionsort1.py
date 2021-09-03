length = int(input())
arr = list(map(int, input().split()))

key = arr[-1]
flag = False
for i in range(1, length):
    arr[-i] = arr[-i - 1]
    if arr[-i] <= key:
        arr[-i] = key
        print(*arr)
        flag = True
        break
    print(*arr)
if not flag:
    arr[0] = key
    print(*arr)

# correct, but the solution quite makeshift, will fix it later.
