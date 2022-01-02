def main():
    n = int(input())

    answer_arr = []
    for i in range(n):
        answer_arr.append((9 ** i * 10 * (i + 1)) % 998244353)
    print(*reversed(answer_arr))


if __name__ == "__main__":
    main()

# wrong answer
