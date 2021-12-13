n, k = list(map(int, input().split()))
initialPos = tuple(map(int, input().split()))
obstacles = set()
for i in range(k):
    obstacles.add(tuple(map(int, input().split())))

boolArr = [True, True, True, True, True, True, True, True]
xArr = [0, 1, 1, 1, 0, -1, -1, -1]
yArr = [1, 1, 0, -1, -1, -1, 0, 1]
multiplier = 1
counter = 0
while any(boolArr):
    for i in range(8):
        if boolArr[i]:
            currentX = initialPos[0] + multiplier * xArr[i]
            currentY = initialPos[1] + multiplier * yArr[i]
            if not 0 < currentX <= n or not 0 < currentY <= n or (currentX, currentY) in obstacles:
                boolArr[i] = False
                continue
            counter += 1
    multiplier += 1
print(counter)

# correct
