def main():
    n, s = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()

    median = arr[n // 2]
    if s == median:
        ans = 0
    elif s < median:
        ans = 0
        for i in range(n // 2 + 1):
            ans += max(arr[i] - s, 0)
    else:
        ans = 0
        for i in range(n // 2, n):
            ans += max(s - arr[i], 0)

    print(ans)


if __name__ == "__main__":
    main()

# correct
