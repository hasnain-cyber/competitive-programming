import math


def main():
    a, b, c = list(map(int, input().split()))

    print(max(math.ceil(c * (a - b) / b), 0))


if __name__ == "__main__":
    main()

# correct
