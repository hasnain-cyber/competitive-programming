import math


def main():
    for _ in range(int(input())):
        n, s = map(int, input().split())

        if s - n**2 + 1 < 0:
            print(0)
        else:
            print(math.ceil((s - n**2 + 1) / (n**2 - n + 1)))


if __name__ == "__main__":
    main()

# correct
