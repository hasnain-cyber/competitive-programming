def main():
    shift = input()
    string = input()

    arr = ["qwertyuiop", "asdfghjkl;", "zxcvbnm,./"]

    for character in string:
        for i in range(3):
            for j in range(len(arr[0])):
                if arr[i][j] == character:
                    if shift == "L":
                        print(arr[i][j + 1], end="")
                    else:
                        print(arr[i][j - 1], end="")


if __name__ == "__main__":
    main()

# correct
