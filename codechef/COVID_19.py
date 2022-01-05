def main():
    for _ in range(int(input())):
        n, m = list(map(lambda x: (int(x) + 1) // 2, input().split()))
        print(n * m)


if __name__ == "__main__":
    main()

# correct
