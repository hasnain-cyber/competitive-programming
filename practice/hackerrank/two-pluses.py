nRows, nColumns = list(map(int, input().split()))
arr = [input() for _ in range(nRows)]


def findCrossArea(row, column):
    usedCells = {(row, column)}
    area = 1

    areaArr.append([area, usedCells])

    topRow, bottomRow = row, row
    leftColumn, rightColumn = column, column
    while True:
        topRow -= 1
        bottomRow += 1
        leftColumn -= 1
        rightColumn += 1
        if topRow >= 0 \
                and bottomRow < nRows \
                and leftColumn >= 0 \
                and rightColumn < nColumns:
            if arr[topRow][column] == 'G' \
                    and arr[bottomRow][column] == 'G' \
                    and arr[row][leftColumn] == 'G' \
                    and arr[row][rightColumn] == 'G':
                area += 4
                usedCells.add((topRow, column))
                usedCells.add((bottomRow, column))
                usedCells.add((row, leftColumn))
                usedCells.add((row, rightColumn))
                areaArr.append([area, usedCells.copy()])
            else:
                break
        else:
            break


areaArr = []
for r in range(nRows):
    for c in range(nColumns):
        if arr[r][c] == 'G':
            findCrossArea(r, c)

maxMul = -1
for i in range(len(areaArr) - 1):
    for j in range(i + 1, len(areaArr)):
        if areaArr[i][1] & areaArr[j][1] == set() and areaArr[i][0] * areaArr[j][0] > maxMul:
            maxMul = areaArr[i][0] * areaArr[j][0]
print(maxMul)

# correct
