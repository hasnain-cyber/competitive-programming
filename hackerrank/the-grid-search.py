import re


def findAllSubstrings(string, substr):
    return [m.start() for m in re.finditer('(?={})'.format(substr), string)]


def findPattern(mainArr, searchArr):
    for i in range(R):
        if i + r > R:
            return False
        else:
            pos_arr = findAllSubstrings(mainArr[i], searchArr[0])
            for pos in pos_arr:
                flag = True
                for j in range(r):
                    currentPositions = findAllSubstrings(mainArr[j + i], searchArr[j])
                    if pos not in currentPositions:
                        flag = False
                        break
                if flag:
                    return True
    return False


for _ in range(int(input())):
    R, C = tuple(map(int, input().split()))
    mainArr = []
    for i in range(R):
        mainArr.append(input())
    r, c = tuple(map(int, input().split()))
    searchArr = []
    for i in range(r):
        searchArr.append(input())

    if findPattern(mainArr, searchArr):
        print('YES')
    else:
        print('NO')

# correct
