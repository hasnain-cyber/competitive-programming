def main():
    n, m = list(map(int, input().split()))

    a = 0
    counter = 0
    while True:
        b = n - a ** 2
        if b < 0:
            break
        if a + b ** 2 == m:
            counter += 1
        a += 1
    print(counter)


if __name__ == "__main__":
    main()

# correct
