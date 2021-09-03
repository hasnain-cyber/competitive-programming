def checkPalindrome(string):
    flag = True
    for i in range(len(string) // 2):
        if not string[i] == string[-i - 1]:
            flag = False
            break
    return flag


for _ in range(int(input())):
    string = input()
    if checkPalindrome(string):
        print(-1)
    else:
        for i in range(len(string) // 2):
            if not string[i] == string[-i - 1]:
                if checkPalindrome(string[:i] + string[i + 1:]):
                    print(i)
                else:
                    print(len(string) - i - 1)
                break

# correct
