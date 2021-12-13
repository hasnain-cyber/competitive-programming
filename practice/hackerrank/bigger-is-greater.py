for _ in range(int(input())):
    string = input()
    length = len(string)

    index1 = None
    for i in range(length - 2, -1, -1):
        if string[i] < string[i + 1]:
            index1 = i
            break

    if index1 is None:
        print('no answer')
    else:
        index2 = None
        for i in range(length - 1, -1, -1):
            if string[i] > string[index1]:
                index2 = i
                break
        answerList = list(string)
        answerList[index1] = string[index2]
        answerList[index2] = string[index1]
        answerList = answerList[:index1 + 1] + list(reversed(answerList[index1 + 1:]))
        for character in answerList:
            print(character, end='')
        print()

# complete
