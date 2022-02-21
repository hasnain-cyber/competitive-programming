from string import ascii_lowercase


def main():
    string = input()

    previous_index = 0
    flag = True
    for character in ascii_lowercase:
        find_index = string.find(character)
        if find_index == -1:
            for i in range(ord(character) + 1, ord("z") + 1):
                if chr(i) in string:
                    flag = False
                    break
            break

        if previous_index > find_index:
            flag = False
            break
        else:
            previous_index = find_index

    print("YES" if flag else "NO")


if __name__ == "__main__":
    main()

# correct
