v = int(input())
l = int(input())
arr = list(map(int, input().split()))

for i in range(l):
    if arr[i] == v:
        print(i)
        break

# correct
