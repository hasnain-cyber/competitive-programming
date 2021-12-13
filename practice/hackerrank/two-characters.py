from itertools import combinations

length = int(input())
string = input()

characterList = []
for character in string:
    if character not in characterList:
        characterList.append(character)


def check(string):
    if len(string) < 3:
        return True
    else:
        ch1 = string[0]
        ch2 = string[1]

        flag = True
        for i in range(2, len(string) - 1, 2):
            if not (ch1 == string[i] and ch2 == string[i + 1]):
                flag = False
                break
        if not len(string) % 2 == 0:
            if not string[-1] == ch1:
                flag = False
        return flag


maxLen = 0
preserveArr = list(combinations(characterList, 2))
for item in preserveArr:
    testString = string
    for character in characterList:
        if character not in item:
            testString = testString.replace(character, '')
    if check(testString) and len(testString) > maxLen:
        maxLen = len(testString)
print(maxLen)

# correct
