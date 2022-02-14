def main():
    n, x = list(map(int, input().split()))

    counter = 0
    for i in range(1, n + 1):
        j = x / i
        if j.is_integer() and 1 <= j <= n:
            counter += 1
    print(counter)


if __name__ == "__main__":
    main()

# correct
