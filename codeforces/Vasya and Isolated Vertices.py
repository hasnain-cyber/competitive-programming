def main():
    n, m = map(int, input().split())

    if n == 1:
        mn = 1
        mx = 1
    else:
        mn = max(0, n - 2 * m)

        # could not solve for max

    print(mn, mx)


if __name__ == "__main__":
    main()

# could not solve for max
