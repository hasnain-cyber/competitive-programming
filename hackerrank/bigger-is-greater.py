def compare(char1, char2):  # return true if char1 > char2
    if ord(char1) > ord(char2):
        return True
    return False


for _ in range(int(input())):
    string = input()
    length = len(string)
    flag = False
    for i in range(length - 1, -1, -1):
        if flag:
            break
        for j in range(i - 1, -1, -1):
            if compare(string[i], string[j]):
                flag = True

                # first switch the characters, than sort them
                string = string[0: j] + string[i] + string[j + 1: i] + string[j] + string[i + 1:]
                string = string[0: j + 1] + ''.join(sorted(string[j + 1:]))
                break
    if flag:
        print(string)
    else:
        print('no answer')

# wrong answer and tle
