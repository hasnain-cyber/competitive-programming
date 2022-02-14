def main():
    n, m = list(map(int, input().split()))

    answer_arr = []
    for i in range(1, m + 1):
        answer_arr.append((1, i))
    for i in range(2, n + 1):
        answer_arr.append((i, m))

    print(len(answer_arr))
    for element in answer_arr:
        print(*element)


if __name__ == "__main__":
    main()

# correct
