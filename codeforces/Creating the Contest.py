def main():
    n = int(input())
    arr = list(map(int, input().split()))

    counter = 1
    max_counter = 0
    last_highest_difficulty = arr[0]
    for i in range(1, n):
        difficulty = arr[i]

        if difficulty > 2 * last_highest_difficulty:
            counter = 1
        else:
            counter += 1

        last_highest_difficulty = difficulty
        max_counter = max(max_counter, counter)

    max_counter = max(max_counter, counter)
    print(max_counter)


if __name__ == "__main__":
    main()

# correct
