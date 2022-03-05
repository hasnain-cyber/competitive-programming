def upper_bound_binary_search(arr, x):
    l, r = 0, len(arr) - 1
    while l <= r:
        mid = (l + r) // 2
        if arr[mid] >= x:
            r = mid - 1
        else:
            l = mid + 1
    return l


def main():
    n = int(input())
    arr = list(map(int, input().split()))

    presum_arr = []
    for i in range(n):
        if i == 0:
            presum_arr.append(arr[i])
        else:
            presum_arr.append(presum_arr[i - 1] + arr[i])

    n_half = (presum_arr[-1] + 1) // 2
    l = upper_bound_binary_search(presum_arr, n_half)
    print(l + 1)


if __name__ == "__main__":
    main()

# correct
