def main():
    string = input()

    flag1, flag2, flag3 = False, False, False
    for character in string:
        if character.isupper():
            flag1 = True
        elif character.islower():
            flag2 = True
        elif character.isdigit():
            flag3 = True
    if flag1 and flag2 and flag3 and len(string) >= 5:
        print("Correct")
    else:
        print("Too weak")


if __name__ == "__main__":
    main()

# correct
