def main():
    n, m = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(n)]

    answer_arr = []
    for i in range(n - 1):
        for j in range(m - 1):
            if arr[i][j] * arr[i][j + 1] * arr[i + 1][j] * arr[i + 1][j + 1] > 0:
                arr[i][j] = 2
                arr[i][j + 1] = 2
                arr[i + 1][j] = 2
                arr[i + 1][j + 1] = 2
                answer_arr.append((i + 1, j + 1))

    counter = 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 1:
                counter += 1
    if counter != 0:
        print(-1)
        return

    print(len(answer_arr))
    for element in answer_arr:
        print(*element)


if __name__ == "__main__":
    main()

# correct
