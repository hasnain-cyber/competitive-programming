def main():
    for _ in range(int(input())):
        n, m = map(int, input().split())
        arr = [input() for _ in range(n)]

        count_black_boxes_column, count_black_boxes_row = [0 for _ in range(m)], [
            0 for _ in range(n)
        ]
        for i in range(n):
            for j in range(m):
                if arr[i][j] == "*":
                    count_black_boxes_column[j] += 1
                    count_black_boxes_row[i] += 1

        mx_painted_cells = float("-inf")
        for i in range(n):
            for j in range(m):
                painted_cells = count_black_boxes_column[j] + count_black_boxes_row[i]
                if arr[i][j] == "*":
                    painted_cells -= 1
                mx_painted_cells = max(mx_painted_cells, painted_cells)

        print(n + m - 1 - mx_painted_cells)


if __name__ == "__main__":
    main()

# correct
