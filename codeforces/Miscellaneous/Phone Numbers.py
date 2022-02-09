from itertools import combinations


def main():
    n = int(input())
    string = input()

    answer = n // 11
    print(min(answer, string.count("8")))


if __name__ == "__main__":
    main()

# correct
