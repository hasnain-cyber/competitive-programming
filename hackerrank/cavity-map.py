n = int(input())
gridArray = []
for _ in range(n):
    gridArray.append([character for character in input()])

for i in range(1, n - 1):
    for j in range(1, n - 1):
        d = gridArray[i][j]
        if gridArray[i + 1][j] < d and gridArray[i - 1][j] < d and gridArray[i][j + 1] < d and gridArray[i][j - 1] < d:
            gridArray[i][j] = 'X'

for row in gridArray:
    for element in row:
        print(element, end='')
    print()

# correct
