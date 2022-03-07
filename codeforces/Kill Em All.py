def main():
    for _ in range(int(input())):
        n, r = map(int, input().split())
        arr = set(map(int, input().split()))

        arr = list(arr)
        n = len(arr)

        ans = 0
        for i in range(n - 1, -1, -1):
            ans += arr[i] - ans * r > 0
        print(ans)


if __name__ == "__main__":
    main()

# could not solve
