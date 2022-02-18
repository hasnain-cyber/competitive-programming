def main():
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    min_sum, min_index = sum(arr[:k]), 0
    current_sum = min_sum
    for i in range(1, n - k + 1):
        new_sum = current_sum - arr[i - 1] + arr[i + k - 1]
        if new_sum < min_sum:
            min_sum = new_sum
            min_index = i
        current_sum = new_sum

    print(min_index + 1)


if __name__ == "__main__":
    main()

# correct
