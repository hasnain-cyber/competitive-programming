def binary_search_modified(arr, element):
    l, r = 0, len(arr) - 1

    ans = -1
    while l <= r:
        mid = (l + r) // 2

        if arr[mid] <= element:
            l = mid + 1
        else:
            ans = mid
            r = mid - 1
    return ans


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

        print(len(answer_arr), *answer_arr)


if __name__ == "__main__":
    main()

# correct
