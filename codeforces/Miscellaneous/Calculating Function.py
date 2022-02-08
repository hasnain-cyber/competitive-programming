def main():
    n = int(input())

    k, p = (n + 1) // 2, n // 2
    print(p * (p + 1) - k ** 2)


if __name__ == "__main__":
    main()

# correct
