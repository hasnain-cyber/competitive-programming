def main():
    for _ in range(int(input())):
        m, x = list(map(int, input().split()))

        for i in range(1, x + 1):
            k = m - 1
            if k == 1:
                print(1)


if __name__ == "__main__":
    main()

# could not solve
