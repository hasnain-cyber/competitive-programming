def calculate_sum_upto(n):
    if n % 2 == 0:
        return n // 2
    else:
        return (n // 2) * (n // 2 + 1) - ((n + 1) // 2) ** 2


def main():
    for _ in range(int(input())):
        l, r = list(map(int, input().split()))

        print(calculate_sum_upto(r) - calculate_sum_upto(l - 1))


if __name__ == "__main__":
    main()

# correct
