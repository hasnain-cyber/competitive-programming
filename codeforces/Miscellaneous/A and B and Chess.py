def main():
    n, m = 8, 8
    arr = [input() for _ in range(n)]

    weight_white, weight_black = 0, 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] == "q":
                weight_black += 9
            elif arr[i][j] == "Q":
                weight_white += 9
            elif arr[i][j] == "r":
                weight_black += 5
            elif arr[i][j] == "R":
                weight_white += 5
            elif arr[i][j] == "b":
                weight_black += 3
            elif arr[i][j] == "B":
                weight_white += 3
            elif arr[i][j] == "n":
                weight_black += 3
            elif arr[i][j] == "N":
                weight_white += 3
            elif arr[i][j] == "p":
                weight_black += 1
            elif arr[i][j] == "P":
                weight_white += 1

    if weight_white > weight_black:
        print("White")
    elif weight_white < weight_black:
        print("Black")
    else:
        print("Draw")


if __name__ == "__main__":
    main()

# correct
