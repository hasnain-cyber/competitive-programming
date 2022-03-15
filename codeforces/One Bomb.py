def main():
    n, m = map(int, input().split())
    arr = [input() for _ in range(n)]

    count_bombs_row, count_bombs_column = [0 for _ in range(n)], [0 for _ in range(m)]

    total_bombs = 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] == "*":
                total_bombs += 1
                count_bombs_row[i] += 1
                count_bombs_column[j] += 1

    for i in range(n):
        for j in range(m):
            destroyed_walls = count_bombs_row[i] + count_bombs_column[j]

            if arr[i][j] == "*":
                destroyed_walls -= 1

            if destroyed_walls == total_bombs:
                print("YES")
                print(i + 1, j + 1)
                return

    print("NO")


if __name__ == "__main__":
    main()

# correct
