def main():
    for t in range(int(input())):
        n, s, k = list(map(int, input().split()))
        arr_k = set(map(int, input().split()))

        min_upper_distance = n - 1
        for i in range(s, 0, -1):
            if i in arr_k:
                continue
            else:
                min_upper_distance = s - i
                break

        min_lower_distance = n - 1
        for i in range(s + 1, n + 1):
            if i in arr_k:
                continue
            else:
                min_lower_distance = i - s
                break

        print(min(min_upper_distance, min_lower_distance))


if __name__ == "__main__":
    main()

# correct
