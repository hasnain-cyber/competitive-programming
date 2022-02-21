def lower_bound_binary_search(arr, x):
    l, r = 0, len(arr) - 1
    while l <= r:
        mid = (l + r) // 2
        if arr[mid] <= x:
            l = mid + 1
        else:
            r = mid - 1
    return l


def main():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()

    for _ in range(int(input())):
        q = int(input())
        print(lower_bound_binary_search(arr, q))


if __name__ == "__main__":
    main()

# correct
