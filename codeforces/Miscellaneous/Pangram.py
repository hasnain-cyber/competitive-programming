def main():
    n = int(input())
    string = input()
    string = string.lower()

    if len(set(string)) == 26:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()

# correct
