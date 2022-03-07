from string import ascii_uppercase


def process_substring(string, l, r):
    substring = string[l - 1 : r]

    temp_dict = {}
    for character in substring:
        if character in temp_dict:
            temp_dict[character] += 1
        else:
            temp_dict[character] = 1

    missing_characters = []
    for character in ascii_uppercase:
        if character not in temp_dict:
            missing_characters.append(character)
        else:
            if temp_dict[character] > 1:
                return

    if not "?" in temp_dict or len(missing_characters) == temp_dict["?"]:
        new_string = ""
        for index, character in enumerate(string):
            if character == "?":
                if l - 1 <= index < r:
                    new_string += missing_characters.pop(0)
                else:
                    new_string += "A"
            else:
                new_string += character

        print(new_string)
        exit(0)


def main():
    string = input()

    for i in range(len(string) - 25):
        process_substring(string, i + 1, i + 26)

    print(-1)


if __name__ == "__main__":
    main()

# correct
