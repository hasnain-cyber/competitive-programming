def main():
    for _ in range(int(input())):
        string = input()

        if len(string) <= 10:
            print(string)
        else:
            print(string[0] + str(len(string) - 2) + string[-1])


if __name__ == "__main__":
    main()

# correct
