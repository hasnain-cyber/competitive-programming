from collections import Counter


def anagramCheck(string):
    length = len(string)
    if not length % 2 == 0:
        return -1
    else:
        length = length // 2

        firstCounter = Counter(string[0:length])
        secondCounter = Counter(string[length:])
        return length - sum((firstCounter & secondCounter).values())


for _ in range(int(input())):
    string = input()
    print(anagramCheck(string))

# correct
