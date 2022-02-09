def main():
    n = int(input())

    n %= 4
    if n == 0 or n == 3:
        print(0)
    else:
        print(1)


if __name__ == "__main__":
    main()

# correct
