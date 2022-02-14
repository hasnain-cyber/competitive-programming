def main():
    n, b, p = list(map(int, input().split()))

    total_bottles = 0
    bottles_per_match = 2 * b + 1
    current_n = n
    while current_n > 1:
        total_bottles += (current_n // 2) * bottles_per_match
        current_n = current_n % 2 + current_n // 2
    print(total_bottles, p * n)


if __name__ == "__main__":
    main()

# correct
