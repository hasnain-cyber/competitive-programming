def main():
    n = int(input())
    string = input()

    num = int(string[::-1], 2) + 1
    string2 = "{0:b}".format(num)
    string2 = string2[::-1]
    if len(string2) > len(string):
        string2 = string2[:-1]
    else:
        string2 = string2 + "0" * (len(string) - len(string2))

    counter = 0
    for i in range(n):
        if string[i] != string2[i]:
            counter += 1
    print(counter)


if __name__ == "__main__":
    main()

# correct
