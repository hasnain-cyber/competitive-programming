def main():
    for _ in range(int(input())):
        n = int(input())

        nOnes, remainder = n // 2, n % 2
        if remainder == 0:
            answer = "1" * nOnes
        else:
            answer = "7" + (nOnes - 1) * "1"

        print(answer)


if __name__ == "__main__":
    main()

# correct
