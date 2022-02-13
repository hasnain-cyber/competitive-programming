import enum


def main():
    n = int(input())
    arr = [list(map(int, input().split())) for _ in range(n)]

    answer_arr = [False for _ in range(n)]
    for i in range(n):
        for j in range(i, n):
            if arr[i][j] == 1:
                answer_arr[i] = True
            elif arr[i][j] == 2:
                answer_arr[j] = True
            elif arr[i][j] == 3:
                answer_arr[i] = True
                answer_arr[j] = True

    indices_arr = []
    for index, boolean in enumerate(answer_arr):
        if not boolean:
            indices_arr.append(index + 1)

    print(len(indices_arr))
    print(*indices_arr)


if __name__ == "__main__":
    main()

# correct
