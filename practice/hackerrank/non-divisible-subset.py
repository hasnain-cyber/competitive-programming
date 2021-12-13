import math

length, k = list(map(int, input().split()))
arr = list(map(lambda x: int(x) % k, input().split()))

setLength = 0

for i in range(1, int(math.ceil(k / 2))):
    count = arr.count(i)
    complementaryCount = arr.count(k - i)
    setLength += max(count, complementaryCount)

if k / 2 in arr:
    setLength += 1
if 0 in arr:
    setLength += 1

print(setLength)

# correct
