import string


def main():
    n, k = list(map(int, input().split()))
    distinct_chars = string.ascii_lowercase[:k]

    password = ""
    pointer = 0
    while len(password) < n:
        password += distinct_chars[pointer]
        pointer = (pointer + 1) % k

    print(password)


if __name__ == "__main__":
    main()

# correct
