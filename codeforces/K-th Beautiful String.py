import math


def main():
    for _ in range(int(input())):
        n, k = map(int, input().split())

        z = math.ceil((math.sqrt(8 * k + 1) - 1) / 2)
        k -= (z * (z - 1)) // 2

        print("a" * (n - z - 1) + "b" + "a" * (z - k) + "b" + "a" * (k - 1))


if __name__ == "__main__":
    main()

# correct
