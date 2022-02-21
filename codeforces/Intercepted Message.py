def binary_search(arr, x, l):
    r = len(arr) - 1
    while l <= r:
        mid = (l + r) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            r = mid - 1
        else:
            l = mid + 1
    return -1


def main():
    n, m = list(map(int, input().split()))
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))

    presum_arr1 = [0]
    for i in range(n):
        presum_arr1.append(presum_arr1[-1] + arr1[i])

    presum_arr2 = [0]
    for i in range(m):
        presum_arr2.append(presum_arr2[-1] + arr2[i])

    pointer1, pointer2 = 0, 0
    counter = 0
    for i in range(1, n + 1):
        s = presum_arr1[i] - presum_arr1[pointer1]

        j_index = binary_search(presum_arr2, s + presum_arr2[pointer2], pointer2 + 1)
        if j_index != -1:
            counter += 1
            pointer1 = i
            pointer2 = j_index

    print(counter)


if __name__ == "__main__":
    main()

# correct
