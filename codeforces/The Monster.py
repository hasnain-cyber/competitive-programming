from math import gcd


def main():
    a, b = list(map(int, input().split()))
    c, d = list(map(int, input().split()))

    g = gcd(a, c)
    if abs(b - d) % g != 0:
        print(-1)
    else:
        n1, n2 = 0, 0
        while True:
            value1 = b + a * n1
            value2 = d + c * n2
            if value1 == value2:
                print(value1)
                return
            elif value1 < value2:
                n1 += 1
            else:
                n2 += 1


if __name__ == "__main__":
    main()

# correct
