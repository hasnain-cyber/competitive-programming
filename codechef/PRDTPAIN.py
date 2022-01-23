def binary_search_modified(arr, element, l, r):
    ans, best = l, abs(element - arr[l])
    while l <= r:
        mid = (l + r) // 2

        if abs(element - arr[mid]) < best:
            best = abs(element - arr[mid])
            ans = mid
        if arr[mid] == element:
            break
        elif arr[mid] > element:
            r = mid - 1
        else:
            l = mid + 1
    return ans


def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        sum = 0
        for i in range(n):
            for j in range(i + 2, n):
                target_k = (arr[i] + arr[j]) / 2
                k = arr[binary_search_modified(arr, target_k, i + 1, j - 1)]
                sum += (k - arr[i]) * (arr[j] - k)
        print(sum)


if __name__ == "__main__":
    main()

# same complexity as editorial solution N^2log(N), but solution is not getting accepted for some reason.