def main():
    n = int(input())
    string = input()

    change = 0
    for element in string:
        if element == "+":
            change += 1
        else:
            change -= 1
        change = max(change, 0)

    print(change)


if __name__ == "__main__":
    main()

# correct
