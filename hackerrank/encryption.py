import math

string = input()

length = len(string)
root = math.sqrt(length)
lowerBound, upperBound = int(math.floor(root)), int(math.ceil(root))

for i in range(upperBound):
    j = i
    while j < length:
        print(string[j], end='')
        j += upperBound
    print('', end=' ')
