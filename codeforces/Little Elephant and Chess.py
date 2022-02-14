def main():
    n, m = 8, 8
    arr = [input() for _ in range(n)]

    for i in range(n):
        counter_black, counter_white = 0, 0
        for j in range(m):
            if j != m - 1 and arr[i][j] == arr[i][j + 1]:
                break
            if arr[i][j] == "B":
                counter_black += 1
            elif arr[i][j] == "W":
                counter_white += 1
        if not (counter_black == 4 and counter_white == 4):
            print("NO")
            return
    print("YES")


if __name__ == "__main__":
    main()

# correct
