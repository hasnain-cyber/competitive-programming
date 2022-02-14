def main():
    for _ in range(int(input())):
        x, y, a, b = list(map(int, input().split()))

        t = (y - x) / (a + b)
        if t.is_integer():
            print(int(t))
        else:
            print(-1)


if __name__ == "__main__":
    main()

# correct
