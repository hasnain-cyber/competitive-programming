length = int(input())
arr = []
for i in range(length):
    temp = input().split()
    arr.append((int(temp[0]), temp[1]))

answerArr = []
index = 0
while True:
    counter = 0
    for element in arr:
        if element[0] == index:
            answerArr.append(element)
            counter += 1
    if counter == 0:
        break
    else:
        index += 1

for element in answerArr:
    print(*element)

# wrong answer, did not understand problem properly
