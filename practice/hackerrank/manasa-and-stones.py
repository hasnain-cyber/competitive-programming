for _ in range(int(input())):
    n = int(input())
    a = int(input())
    b = int(input())

    answerArr = []
    for i in range(n):
        ele = a * (n - 1 - i) + b * i
        if ele not in answerArr:
            answerArr.append(ele)

    answerArr.sort()
    for element in answerArr:
        print(element, end=' ')
    print()

# correct
