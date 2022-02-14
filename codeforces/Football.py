def main():
    string = input()

    check_string1 = "0" * 7
    check_string2 = "1" * 7

    if check_string1 in string or check_string2 in string:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()

# correct
