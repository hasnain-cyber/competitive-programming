def binary_search_modified(arr, element):
    l, r = 0, len(arr) - 1

    while l <= r:
        mid = (l + r) // 2

        if arr[mid] <= element:
            l = mid + 1
        else:
            r = mid - 1
    return mid


def main():
    for _ in range(int(input())):
        n = int(input())
        disk_arr = list(map(int, input().split()))
        answer_arr = []

        for current_disk_radius in disk_arr:
            found_index = binary_search_modified(answer_arr, current_disk_radius)
            if found_index == -1:
                answer_arr.append(current_disk_radius)
            else:
                answer_arr[found_index] = current_disk_radius

        print(len(answer_arr), *list(sorted(answer_arr)))


if __name__ == "__main__":
    # main()
    print(binary_search_modified([1, 2, 3, 4, 5, 6, 8, 9, 10], 8))

# could not solve
