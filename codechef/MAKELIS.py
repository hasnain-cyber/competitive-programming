def main():
    for _ in range(int(input())):
        k = int(input())

        k = 100
        answer_arr = list(range(1, 100 - k + 1)) + list(reversed(range(100 - k + 1, 101)))
        print(100)
        print(*answer_arr)


if __name__ == "__main__":
    main()

# could not solve