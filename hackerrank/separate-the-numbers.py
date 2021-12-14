for _ in range(int(input())):
    string = input()
    length = len(string)

    findFlag = False
    for i in range(length):
        currentNumber = string[:i + 1]
        currentIndex = 0

        while True:
            if currentIndex + len(currentNumber) == length:
                findFlag = True
                break

            nextNumber = str(int(currentNumber) + 1)
            nextIndex = string.find(nextNumber)
            if nextIndex == currentIndex + len(currentNumber):
                currentNumber = nextNumber
                currentIndex = nextIndex
            else:
                findFlag = False
                break
        if findFlag:
            break
    if findFlag:
        print('YES')
    else:
        print('NO')

# wrong answer
