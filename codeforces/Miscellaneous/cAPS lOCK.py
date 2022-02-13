def main():
    string = input()

    if len(string) > 1:
        flag1 = True if string[0].isupper() else False
        flag2 = True if string[1:].isupper() else False

        if (flag1 and flag2) or (not flag1 and flag2):
            print(string.swapcase())
        else:
            print(string)
    else:
        print(string.swapcase())


if __name__ == "__main__":
    main()

# correct
