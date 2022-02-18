def main():
    arr = [input() for _ in range(4)]

    for i in range(3):
        for j in range(3):
            counter_black, counter_white = 0, 0

            if arr[i][j] == ".":
                counter_white += 1
            elif arr[i][j] == "#":
                counter_black += 1
            if arr[i + 1][j] == ".":
                counter_white += 1
            elif arr[i + 1][j] == "#":
                counter_black += 1
            if arr[i][j + 1] == ".":
                counter_white += 1
            elif arr[i][j + 1] == "#":
                counter_black += 1
            if arr[i + 1][j + 1] == ".":
                counter_white += 1
            elif arr[i + 1][j + 1] == "#":
                counter_black += 1

            if counter_black >= 3 or counter_white >= 3:
                print("YES")
                return

    print("NO")


if __name__ == "__main__":
    main()

# correct
