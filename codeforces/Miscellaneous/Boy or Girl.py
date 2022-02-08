def main():
    string = input()
    counter = len(set(string))

    if counter % 2 == 0:
        print("CHAT WITH HER!")
    else:
        print("IGNORE HIM!")


if __name__ == "__main__":
    main()

# correct
