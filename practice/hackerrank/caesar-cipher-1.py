length = int(input())
stringArr = list(input())
k = int(input())

for i in range(length):
    ordChar = ord(stringArr[i])
    if 65 <= ordChar <= 90:
        newOrd = ordChar + k
        while newOrd > 90:
            newOrd = 65 + newOrd - 91
        stringArr[i] = chr(newOrd)
    elif 97 <= ordChar <= 122:
        newOrd = ordChar + k
        while newOrd > 122:
            newOrd = 97 + newOrd - 123
        stringArr[i] = chr(newOrd)
for character in stringArr:
    print(character, end='')

# correct
