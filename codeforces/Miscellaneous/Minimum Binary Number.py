def main():
    _ = int(input())
    string = input()

    if string == "0":
        print("0")
    else:
        counter = string.count("0")
        print("1" + "0" * counter)


if __name__ == "__main__":
    main()

# correct
