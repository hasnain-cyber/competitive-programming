def main():
    n = int(input())
    arr = list(map(int, input().split()))

    x = 1
    s = sum(arr)
    counter = 0
    while x <= 5:
        if (x + s) % (n + 1) != 1:
            counter += 1
        x += 1
    print(counter)


if __name__ == "__main__":
    main()

# correct
