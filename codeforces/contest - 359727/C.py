def main():
    for _ in range(int(input())):
        n, x = tuple(map(int, input().split()))
        if n <= 2:
            print(1)
        else:
            print((n - 3) // x + 2)


if __name__ == '__main__':
    main()

# correct