def main():
    string = input()
    if string != "".join(reversed(string)):
        print("NO")
        return
    else:
        test_string = "AHIMOTUVWXY"
        for character in string:
            if character not in test_string:
                print("NO")
                return
        print("YES")


if __name__ == "__main__":
    main()

# correct
