import math


def main():
    n, k = list(map(int, input().split()))

    answer = (-1 + math.sqrt(1 + 8 / 5 * (240 - k))) // 2
    print(int(min(answer, n)))


if __name__ == "__main__":
    main()

# correct
