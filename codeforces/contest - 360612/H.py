def main():
    n, m = list(map(int, input().split()))
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    ans = m
    for x in range(m):
        for i in range(n):
            value = b[i] - x


if __name__ == "__main__":
    main()

# could not solve
