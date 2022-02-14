def main():
    n, t = list(map(int, input().split()))

    for i in range(10 ** (n - 1), 10 ** n):
        if i % t == 0:
            print(i)
            return
    print(-1)


if __name__ == "__main__":
    main()

# correct
