string = input()
length = len(string)

counter = 0
for a in range(length - 3):
    d = length - 1
    while a < d:
        if string[a] == string[d]:
            secondString = string[a + 1:d]
            length2 = len(secondString)
            for b in range(length2 - 1):
                c = length2 - 1
                while b < c:
                    if secondString[b] == secondString[c]:
                        counter += 1
                    c -= 1
        d -= 1
print(counter)

# tle
