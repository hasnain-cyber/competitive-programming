def main():
    for _ in range(int(input())):
        h, m = list(map(int, input().split()))

        answer = 60 * (24 - h) - m
        print(answer)


if __name__ == "__main__":
    main()

# correct
