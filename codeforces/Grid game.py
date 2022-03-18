def main():
    string = input()

    upper_right_filled = False
    bottom_left_filled = False

    for character in string:
        if character == "0":
            if bottom_left_filled:
                print(1, 1)
            else:
                print(3, 1)
            bottom_left_filled = not bottom_left_filled
        else:
            if upper_right_filled:
                print(1, 1)
            else:
                print(1, 3)
            upper_right_filled = not upper_right_filled


if __name__ == "__main__":
    main()

# correct
