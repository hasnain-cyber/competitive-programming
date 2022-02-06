def main():
    for _ in range(int(input())):
        n = int(input())
        n, k = list(map(int, input().split()))

        if k > n // 2:
            print(-1)
        else:
            for i in range(n // 2):
                print(
                    i,
                )


if __name__ == "__main__":
    main()

# could not think of any solution
