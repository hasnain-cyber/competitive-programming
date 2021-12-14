def isKaprekar(n):
    nSquare = str(n ** 2)
    d = len(nSquare) // 2

    if d == 0:
        firstNum = 0
        secondNum = n ** 2
    else:
        firstNum = int(nSquare[0: d])
        secondNum = int(nSquare[d:])
    if firstNum + secondNum == n:
        return True
    return False


p = int(input())
q = int(input())

flag = False
for i in range(p, q + 1):
    if isKaprekar(i):
        flag = True
        print(i, end=' ')
if not flag:
    print('INVALID RANGE')

# correct
