from string import ascii_lowercase


def main():
    string = input()

    answer_string = ""
    for test_character in reversed(ascii_lowercase):
        if test_character in string:
            answer_string = test_character * string.count(test_character)
            break

    print(answer_string)


if __name__ == "__main__":
    main()

# correct
