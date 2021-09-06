length = int(input())
arr = []
for i in range(length):
    temp = input().split()
    arr.append((int(temp[0]), temp[1]))

answerArr = [[] for i in range(length)]
dashCounter = 0
for element in arr:
    if dashCounter < length // 2:
        answerArr[element[0]].append('-')
        dashCounter += 1
    else:
        answerArr[element[0]].append(element[1])

for element1 in answerArr:
    for element2 in element1:
        print(element2, end=' ')

# correct
