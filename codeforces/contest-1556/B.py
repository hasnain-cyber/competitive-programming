def findMEX(testString):
    if not ('0' in testString):
        return 0
    elif not ('1' in testString):
        return 1
    else:
        return 2


def minMEX(miniString):
    minValue = -1
    for i in range(len(miniString)):
        s1 = miniString[: i + 1]
        s2 = miniString[i + 1:]
        if not s2 == '':
            mex = findMEX(s1) + findMEX(s2)
        else:
            mex = findMEX(s1)
        if mex < minValue or minValue == -1:
            minValue = mex
    return minValue


for _ in range(int(input())):
    string = input()
    print(minMEX(string))
