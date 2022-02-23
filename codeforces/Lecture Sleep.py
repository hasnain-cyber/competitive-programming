def main():
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))

    prefix_sum_arr = [0]
    for i in range(n):
        prefix_sum_arr.append(prefix_sum_arr[-1] + (arr[i] if arr2[i] == 1 else 0))

    max_value = 0
    for i in range(n - k + 1):
        if i == 0:
            window_sum = sum(arr[:k])
        else:
            window_sum += arr[i + k - 1] - arr[i - 1]

        test_value = (
            prefix_sum_arr[-1] - prefix_sum_arr[i + k] + prefix_sum_arr[i] + window_sum
        )
        max_value = max(max_value, test_value)

    print(max_value)


if __name__ == "__main__":
    main()

# correct
