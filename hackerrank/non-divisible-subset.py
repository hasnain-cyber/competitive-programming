length, k = list(map(int, input().split()))
arr = set(map(int, input().split()))


def checkCombination(checkSet, checkNum):
    for testNum in checkSet:
        if (testNum + checkNum) % k == 0:
            return False
    return True


setList = [{element} for element in arr]
for element in arr:
    for currentSet in setList:
        if checkCombination(currentSet, element):
            currentSet.add(element)
print(max([len(element) for element in setList]))

# tle
