import math


def main():
    for _ in range(int(input())):
        n = int(input())

        max_set_bit = math.floor(math.log2(n))
        print(2**max_set_bit - 1)


if __name__ == "__main__":
    main()

# correct
