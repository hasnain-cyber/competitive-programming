for _ in range(int(input())):
    n = int(input())
    string = input()

    flag = True
    for character in string:
        if character == '_':
            continue
        if string.count(character) == 1:
            flag = False
            break
    if flag:
        if '_' in string:
            print('YES')
        else:
            flag = True
            for i in range(1, n - 1):
                if string[i - 1] != string[i] and string[i + 1] != string[i]:
                    flag = False
            if flag:
                print('YES')
            else:
                print('NO')
    else:
        print('NO')

# correct
