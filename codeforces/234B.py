def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    answer_arr = []
    for i in range(n):
        answer_arr.append((i, arr[i]))
    answer_arr.sort(key=lambda x: x[1])

    print(answer_arr[n - k][1])
    for i in range(n - k, n):
        print(answer_arr[i][0] + 1, end=" ")


if __name__ == "__main__":
    main()
