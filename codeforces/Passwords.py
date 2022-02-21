def main():
    n, k = list(map(int, input().split()))
    arr = [input() for _ in range(n)]
    correct_length = len(input())

    less_length_passwords, same_length_passwords = 0, 0
    for element in arr:
        check_length = len(element)
        if check_length == correct_length:
            same_length_passwords += 1
        elif check_length < correct_length:
            less_length_passwords += 1

    min_time = (less_length_passwords // k) * 5 + less_length_passwords + 1
    max_time = (
        ((less_length_passwords + same_length_passwords - 1) // k) * 5
        + less_length_passwords
        + same_length_passwords
    )

    print(min_time, max_time)


if __name__ == "__main__":
    main()

# correct
