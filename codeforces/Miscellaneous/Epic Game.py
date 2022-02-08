from math import gcd


def main():
    a, b, n = list(map(int, input().split()))

    turn = 0
    while True:
        if turn == 0:
            turn = 1
            to_take = gcd(n, a)
        else:
            turn = 0
            to_take = gcd(n, b)
        if n == to_take:
            print(1 - turn)
            break
        elif n < to_take:
            print(turn)
            break
        n -= to_take


if __name__ == "__main__":
    main()

# correct
