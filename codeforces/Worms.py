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

    nQueries = int(input())
    queries = list(map(int, input().split()))

    lower_bound_arr = []
    s = 0
    for i in range(n):
        s += arr[i]
        lower_bound_arr.append(s)

    for element in queries:
        print(upper_bound_binary_search(lower_bound_arr, element) + 1)


if __name__ == "__main__":
    main()

# correct
