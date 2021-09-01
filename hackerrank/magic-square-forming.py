magicSquaresArr = [[[8, 1, 6], [3, 5, 7], [4, 9, 2]],
                   [[6, 1, 8], [7, 5, 3], [2, 9, 4]],
                   [[4, 9, 2], [3, 5, 7], [8, 1, 6]],
                   [[2, 9, 4], [7, 5, 3], [6, 1, 8]],
                   [[8, 3, 4], [1, 5, 9], [6, 7, 2]],
                   [[4, 3, 8], [9, 5, 1], [2, 7, 6]],
                   [[6, 7, 2], [1, 5, 9], [8, 3, 4]],
                   [[2, 7, 6], [9, 5, 1], [4, 3, 8]]]

arr = []
for _ in range(3):
    arr.append(list(map(int, input().split())))


def calculateCost(checkSquare, magicSquare):
    cost = 0
    for i in range(3):
        for j in range(3):
            cost += abs(checkSquare[i][j] - magicSquare[i][j])
    return cost


minCost = -1
for k in range(8):
    currentCost = calculateCost(arr, magicSquaresArr[k])
    if currentCost < minCost or minCost == -1:
        minCost = currentCost
print(minCost)

# correct
