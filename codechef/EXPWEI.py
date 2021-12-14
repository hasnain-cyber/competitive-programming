from fractions import Fraction

for _ in range(int(input())):
    n = int(input())
    tempFraction = Fraction(n * ((n + 1) ** 2) / 4)
    p, q = tempFraction.numerator, tempFraction.denominator
    print(p * (q ** -1 % 998244353))

# wrong
