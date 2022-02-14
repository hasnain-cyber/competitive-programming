def main():
    n, m = list(map(int, input().split()))
    arr = [list(map(int, input().split())) for _ in range(n)]

    if n < 2 or m < 2:
        print(-1)
        return

    common_index = -1
    for j in range(m - 1):
        flag = True
        for i in range(n):
            if arr[i][j] == arr[i][j + 1]:
                flag = False
                break
        if flag:
            common_index = j - 1
            break

    if common_index == -1:
        print(-1)
        return

    answer_arr = []
    for i in range(n - 1):
        for j in range(m - 1):
            if j == common_index:
                continue

            color = arr[i][j + 1]
            answer_arr.append((i + 1, j + 1, color))

    for i in range(n - 1):
        answer_arr.append((i + 1, common_index + 1, arr[i][common_index]))

    print(len(answer_arr))
    for element in answer_arr:
        print(*element)


if __name__ == "__main__":
    main()

# could not submit