def main():
    a, b = list(map(int, input().split()))

    counter = 0
    current_a, current_b = a, 0
    while current_a > 0:
        counter += current_a
        current_b += current_a

        current_a = current_b // b
        current_b -= current_a * b
    print(counter)


if __name__ == "__main__":
    main()

# correct
