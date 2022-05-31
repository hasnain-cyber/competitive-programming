def main():
    n = int(input())
    arr = list(map(int, input().split()))

    answer_arr = [(0, 0, 0)]
    for i in range(n):
        if arr[i] == 0:
            temp_tuple = (
                min(answer_arr[-1][0], answer_arr[-1][1], answer_arr[-1][2]) + 1,
                answer_arr[-1][1] + 1,
                answer_arr[-1][2] + 1,
            )
        elif arr[i] == 1:
            temp_tuple = (
                min(answer_arr[-1][0], answer_arr[-1][1], answer_arr[-1][2]) + 1,
                min(answer_arr[-1][0], answer_arr[-1][2]),
                min(answer_arr[-1][0], answer_arr[-1][1], answer_arr[-1][2]) + 1,
            )
        elif arr[i] == 2:
            temp_tuple = (
                min(answer_arr[-1][0], answer_arr[-1][1], answer_arr[-1][2]) + 1,
                min(answer_arr[-1][0], answer_arr[-1][1], answer_arr[-1][2]) + 1,
                min(answer_arr[-1][0], answer_arr[-1][1]),
            )
        else:
            temp_tuple = (
                min(answer_arr[-1][0], answer_arr[-1][1], answer_arr[-1][2]) + 1,
                min(answer_arr[-1][0], answer_arr[-1][2]),
                min(answer_arr[-1][0], answer_arr[-1][1]),
            )

        answer_arr.append(temp_tuple)

    print(min(answer_arr[-1]))


if __name__ == "__main__":
    main()

# correct
