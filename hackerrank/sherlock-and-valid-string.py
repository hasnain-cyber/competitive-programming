from collections import Counter

freqCounter = Counter(Counter(input()).values())
length = len(freqCounter.keys())
if length == 1:
    print('YES')
elif length == 2:
    keys = list(freqCounter.keys())
    values = list(freqCounter.values())

    flag = False
    for i in range(len(keys)):
        if keys[i] == 1 and values[i] == 1:
            flag = True
            break

    if flag or (abs(keys[0] - keys[1]) == 1 and 1 in values):
        print('YES')
    else:
        print('NO')
else:
    print('NO')

# correct
