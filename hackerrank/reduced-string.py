stringList = [character for character in input()]

flag = True
while flag:
    flag = False
    testStringList = stringList

    for i in range(len(stringList) - 1):
        if stringList[i] == stringList[i + 1]:
            testStringList = testStringList[:i] + testStringList[i + 2:]
            flag = True
            break
    stringList = testStringList
if len(stringList) > 0:
    for character in stringList:
        print(character, end='')
else:
    print('Empty String')

# correct
