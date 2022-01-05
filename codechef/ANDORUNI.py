def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        ans = 0
        for i in range(n - 1):
            for j in range(i + 1, n):
                ans |= arr[i] & arr[j]
        print(ans)


if __name__ == "__main__":
    main()

# tle
