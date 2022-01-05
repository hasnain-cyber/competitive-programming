def main():
    l, r = int(input()), int(input())

    max_value = 0
    for a in range(l, r):
        for b in range(a + 1, r + 1):
            current_value = a ^ b
            if current_value > max_value:
                max_value = current_value
    print(max_value)


if __name__ == "__main__":
    main()

# correct
