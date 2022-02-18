def main():
    for _ in range(int(input())):
        n, k = list(map(int, input().split()))

        if k % 2 != n % 2 or n < k ** 2:
            print("NO")
            continue
        print("YES")


if __name__ == "__main__":
    main()

# correct
