string = input()


def check(string):
    checkedList = []

    oddFlag = False
    for character in string:
        if character in checkedList:
            continue
        else:
            checkedList.append(character)
            count = string.count(character)
            if not count % 2 == 0:
                oddFlag = not oddFlag
                if not oddFlag:
                    return 'NO'
    return 'YES'


print(check(string))

# correct
