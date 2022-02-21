def main():
    string = input()
    n = len(string)

    counter = 0

    if n > 1:
        counter += 2 ** n - 2

    for i in range(n):
        if string[i] == "7":
            counter += 2 ** (n - i - 1)

    print(counter + 1)


if __name__ == "__main__":
    main()

# correct
