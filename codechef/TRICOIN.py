import math


def main():
    for _ in range(int(input())):
        n = int(input())
        print(math.floor((math.sqrt(8 * n + 1) - 1) / 2))


if __name__ == "__main__":
    main()

# correct
