def main():
    n, m = list(map(int, input().split()))

    k = 1
    while True:
        if k // m + n == k:
            print(k)
            return
        else:
            k += 1


if __name__ == "__main__":
    main()

# correct
