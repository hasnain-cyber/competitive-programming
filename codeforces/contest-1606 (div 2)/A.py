def checkEqualCount(string):
    counter1, counter2 = 0, 0
    for i in range(len(string) - 1):
        if string[i] == 'a' and string[i + 1] == 'b':
            counter1 += 1
        if string[i] == 'b' and string[i + 1] == 'a':
            counter2 += 1
    return counter1 == counter2


def flipCharacter(string, i):
    if string[i] == 'a':
        string[i] = 'b'
    else:
        string[i] = 'a'
    return string


def handleProcess(string):
    if checkEqualCount(string):
        for character in string:
            print(character, end='')
        print()
        return True
    else:
        for i in range(len(string)):
            checkString = flipCharacter(string, i)
            return handleProcess(checkString)


for _ in range(int(input())):
    string = list(input())
    handleProcess(string)

# correct
