def main():
    string = input()

    lowercase_count = 0
    for character in string:
        if character.islower():
            lowercase_count += 1
    if lowercase_count >= (len(string) + 1) // 2:
        print(string.lower())
    else:
        print(string.upper())


if __name__ == "__main__":
    main()

# correct
