def main():
    string = input()
    n = len(string)

    left, right = [], []
    for i in range(n):
        if string[i] == "l":
            left.append(i + 1)
        else:
            right.append(i + 1)

    for element in right:
        print(element)
    for element in reversed(left):
        print(element)


if __name__ == "__main__":
    main()

# correct
