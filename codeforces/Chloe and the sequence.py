def main():
    n, k = list(map(int, input().split()))

    while True:
        if k == 2 ** n:
            print(n + 1)
            break
        else:
            if k > 2 ** n:
                k = 2 ** (n + 1) - k
            n -= 1


if __name__ == "__main__":
    main()

# correct
