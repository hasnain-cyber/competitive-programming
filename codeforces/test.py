a = 10
b = 25
c = 15
res = 0

while b > 0:
    res += (a % c) + (c % a)
    b -= (a % c)
    a, b = b, a  # Swap the values of a and b

    print(a, b, c)
    print(res)

# print(res, b)
