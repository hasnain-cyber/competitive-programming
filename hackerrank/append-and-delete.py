string1 = input()
l1 = len(string1)
string2 = input()
l2 = len(string2)
nOperations = int(input())

i = 0
for i in range(min(l1, l2)):
    if not string1[i] == string2[i]:
        break
minOperations = l1 + l2 - 2 * i
if minOperations <= nOperations:
    remainingOperations = nOperations - minOperations
    if remainingOperations % 2 == 0 or remainingOperations > l1:
        print('Yes')
else:
    print('No')

# wrong answer
