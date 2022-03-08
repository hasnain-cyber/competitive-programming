def check_equal(string, substring):
    flag = True
    for i in range(len(string)):
        if string[i] != substring[i % len(substring)]:
            flag = False
            break
    return flag


def main():
    n, k = map(int, input().split())
    string = input()

    period = 0
    for i in range(n):
        if check_equal(string[i + 1 :], string[: i + 1]):
            period = i + 1
            break

    print(string[:period] * k + string[period:])


if __name__ == "__main__":
    main()

# correct
