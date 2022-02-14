import math


def main():
    n1, n2 = list(map(int, input().split()))

    k1 = int(math.sqrt(n1))
    k2 = int((-1 + math.sqrt(1 + 4 * n2)) / 2)

    if k1 - 1 < k2:
        print("Vladik")
    else:
        print("Valera")


if __name__ == "__main__":
    main()

# correct
