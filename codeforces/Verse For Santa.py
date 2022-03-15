def find_index(arr, x):
    for index, element in enumerate(arr):
        if element == x:
            return index
    return -1


def main():
    for _ in range(int(input())):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))

        s = sum(arr)
        if s <= k:
            print(0)
            continue
        else:
            index = 0
            temp_sum = 0
            for i in range(n):
                temp_sum += arr[i]
                if temp_sum > k:
                    index = i
                    break

            print(find_index(arr, max(arr[: index + 1])) + 1)


if __name__ == "__main__":
    main()

# correct
