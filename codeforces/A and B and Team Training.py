def main():
    n, m = map(int, input().split())

    print(min(n, m, (n + m) // 3))


if __name__ == "__main__":
    main()

# correct
