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
    n, k = list(map(int, input().strip().split()))
    arr = list(map(int, input().strip().split()))

    i = 0
    counter = 0
    while i < n:
        location = arr[i] + k
        upper_bound_element = upper_bound_binary_search(arr, location) + 1
        print(location, upper_bound_element)
        if upper_bound_element == location:
            counter += 1
            i = upper_bound_element + k - 1
        else:
            counter += 2
            i = upper_bound_element + k - 1
    print(counter)


if __name__ == "__main__":
    main()

# wrong answer
