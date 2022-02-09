def check_vowels(string):
    vowels = {"a", "e", "i", "o", "u", "y"}
    for i in range(len(string) - 1):
        if string[i] in vowels and string[i + 1] in vowels:
            return i + 1
    return -1


def main():
    _ = int(input())
    string = input()

    while check_vowels(string) != -1:
        index = check_vowels(string)
        string = string[:index] + string[index + 1 :]
    print(string)


if __name__ == "__main__":
    main()

# correct
