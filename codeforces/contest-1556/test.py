string = input()

for i in range(len(string)-1):
    s1 = string[: i + 1]
    s2 = string[i + 1:]
    print(s1, s2)
