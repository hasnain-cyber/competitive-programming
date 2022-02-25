def main():
    for _ in range(int(input())):
        n, m = map(int, input().split())

        divisor = n // m

        ten_sum = 0
        for i in range(1, 11):
            ten_sum += (i * m) % 10

        s = ten_sum * (divisor // 10)
        for i in range(1, divisor % 10 + 1):
            s += (i * m) % 10
        print(s)


if __name__ == "__main__":
    main()

# correct
