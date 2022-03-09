def lower_bound_binary_search(arr, x):
    l, r = 0, len(arr) - 1
    while l <= r:
        mid = (l + r) // 2
        if arr[mid] <= x:
            l = mid + 1
        else:
            r = mid - 1
    return r


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
    n, m, k = map(int, input().split())
    special_items = list(map(int, input().split()))
    special_items.sort()

    counter = 0
    tolerance = 0
    while len(special_items) > 0:
        mn = min(special_items)
        page_no = (mn - 1) // k + 1
        page_start, page_end = (page_no - 1) * k + 1, page_no * k

        marked_values = []
        for element in range(page_start + tolerance, page_end + 1 + tolerance):
            if element in special_items:
                marked_values.append(element)
                tolerance += 1
        for value in marked_values:
            special_items.remove(value)

        counter += 1

    print(counter)


if __name__ == "__main__":
    main()

# could not solve
