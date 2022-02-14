def main():
    for _ in range(int(input())):
        r, g, b = list(map(int, input().split()))

        r, g, b = (
            max(r, g, b),
            min(r, g, b),
            sum([r, g, b]) - max(r, g, b) - min(r, g, b),
        )

        if r - 1 > g + b:
            print("No")
        else:
            print("Yes")


if __name__ == "__main__":
    main()

# correct
