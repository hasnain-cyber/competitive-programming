from collections import Counter

string1 = input()
string2 = input()

commonCounter = (sum((Counter(string1) & Counter(string2)).values()))
print(len(string1) + len(string2) - 2 * commonCounter)

# correct
