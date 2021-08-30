for _ in range(int(input())):
    mainGrid = []
    patternGrid = []

    R, C = list(map(int, input().split()))
    for i in range(R):
        mainGrid.append(input())
    r, c = list(map(int, input().split()))
    for i in range(r):
        patternGrid.append(input())

    index = -1
    i = 0
    for i in range(R - r + 1):
        index = mainGrid[i].find(patternGrid[0])
        if not index == -1:
            break

    if index == -1:
        print('NO')
    elif r == 1:
        print('YES')
    else:
        flag = True
        currentPosition = i
        for j in range(1, r):
            currentPosition += 1
            if currentPosition == R - 1 or not mainGrid[currentPosition].find(patternGrid[j]) == index:
                flag = False
                break
        if not flag:
            print('NO')
        else:
            print('YES')

# wrong answer
