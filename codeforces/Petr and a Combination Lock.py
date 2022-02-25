def find_answer(current_sum, arr, index):
    current_sum %= 360

    if index == len(arr) - 1:
        return (current_sum + arr[index]) % 360 == 0 or (
            current_sum - arr[index]
        ) % 360 == 0

    return find_answer(current_sum + arr[index], arr, index + 1) or find_answer(
        current_sum - arr[index], arr, index + 1
    )


def main():
    n = int(input())
    arr = [int(input()) for _ in range(n)]

    print("YES" if find_answer(0, arr, 0) else "NO")


if __name__ == "__main__":
    main()

# correct
