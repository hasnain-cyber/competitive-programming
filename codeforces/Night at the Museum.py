def main():
    string = input()
    current_char = "a"

    counter = 0
    for character in string:
        cost = abs(ord(character) - ord(current_char))
        counter += min(cost, 26 - cost)
        current_char = character
    print(counter)


if __name__ == "__main__":
    main()

# correct
