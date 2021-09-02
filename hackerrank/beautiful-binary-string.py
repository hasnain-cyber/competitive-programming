length = int(input())
string = input()

print((length - len(string.replace('010', ''))) // 3)

# correct
