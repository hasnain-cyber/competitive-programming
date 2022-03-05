def lower_bound_binary_search(arr, x):
    l, r = 0, len(arr) - 1

    while l <= r:
        mid = (l + r) // 2
        if arr[mid] <= x:
            l = mid + 1
        else:
            r = mid - 1
    return r


def main():
    n, d = map(int, input().split())
    arr = list(map(int, input().split()))

    counter = 0
    for i in range(n):
        index = lower_bound_binary_search(arr, arr[i] + d)

        if arr[index] - arr[i] > d:
            continue
        else:
            k = index - i - 1
            counter += k * (k + 1) // 2
    print(counter)


if __name__ == "__main__":
    main()

# correct
