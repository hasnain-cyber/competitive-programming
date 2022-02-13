def main():
    for _ in range(int(input())):
        n, k = list(map(int, input().split()))
        arr = list(map(int, input().split()))

        final_range = (1, max(arr) + k)
        for element in arr:
            mn, mx = max(1, element - k), element + k

            if mn > final_range[0]:
                final_range = (mn, final_range[1])
            if mx < final_range[1]:
                final_range = (final_range[0], mx)

        if final_range[0] <= final_range[1]:
            print(final_range[1])
        else:
            print(-1)


if __name__ == "__main__":
    main()

# correct