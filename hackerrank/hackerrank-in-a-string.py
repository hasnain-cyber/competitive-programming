hackerrankString = 'hackerrank'


def findIndices(findCharacter, string):
    returnArr = []
    for i in range(len(string)):
        if string[i] == findCharacter:
            returnArr.append(i)
    return returnArr


for _ in range(int(input())):
    string = input()

    prevIndex = -1
    for character in hackerrankString:
        currentIndices = findIndices(character, string)
        flag = False
        for index in currentIndices:
            if index > prevIndex:
                flag = True
                prevIndex = index
                break
        if not flag:
            break
    if flag:
        print('YES')
    else:
        print('NO')

# correct
