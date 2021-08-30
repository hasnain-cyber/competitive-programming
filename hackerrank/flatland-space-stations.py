import math

n, m = list(map(int, input().split()))
c = set(map(int, input().split()))

maxCounter = 0
counter = 0
for node in range(n):  # check for chain first
    if node not in c:
        counter += 1
    else:
        if counter > maxCounter:
            maxCounter = counter
        counter = 0
maxCounter = int(math.ceil(maxCounter / 2))

# then check for edge cases at the ends
minStation, maxStation = min(c), n - max(c) - 1
if maxCounter < minStation:
    maxCounter = minStation
if maxCounter < maxStation:
    maxCounter = maxStation
print(maxCounter)
