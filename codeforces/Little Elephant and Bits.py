def main():
    string = input()
    if string.count("0") == 0:
        print(string[1:])
    else:
        string2 = ""
        for i in range(len(string)):
            if string[i] == "0":
                string2 = string[:i] + string[i + 1 :]
                break
        print(string2)


if __name__ == "__main__":
    main()

# correct
