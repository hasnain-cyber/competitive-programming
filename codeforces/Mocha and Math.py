def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        ans = arr[0]
        for i in range(1, n):
            ans &= arr[i]

        print(ans)


if __name__ == "__main__":
    main()

# correct
