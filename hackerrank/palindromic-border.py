string = input()
length = len(string)
countDict = dict()


def isPalindrome(s):
    length = len(s) // 2
    for i in range(length):
        if not s[i] == s[-i - 1]:
            return False
    return True


def countBorderPalindromes(s):
    length = len(s)

    counter = 0
    for i in range(1, length):
        if s[:i] == s[-i:] and isPalindrome(s[:i]):
            counter += 1

    countDict[s] = counter
    return counter


totalCounter = 0
for i in range(length):
    for j in range(i + 1, length):
        subString = string[i: j + 1]
        if subString in countDict.keys():
            totalCounter += countDict[subString]
        else:
            totalCounter += countBorderPalindromes(subString)
print(totalCounter)

# tle
