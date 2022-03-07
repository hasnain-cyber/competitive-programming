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
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort()

    for element in b:
        index = lower_bound_binary_search(a, element)
        print(index + 1, end=" ")


if __name__ == "__main__":
    main()

# correct
