def main():
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    s, reserve = 0, 0
    for i in range(n):
        current_candies = arr[i] + reserve
        s += min(current_candies, 8)
        reserve = max(current_candies - 8, 0)

        if s >= k:
            print(i + 1)
            return

    print(-1)


if __name__ == "__main__":
    main()

# correct
