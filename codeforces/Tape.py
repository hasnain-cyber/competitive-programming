def main():
    n, m, k = map(int, input().split())
    arr = list(map(int, input().split()))

    difference_arr = [(i, arr[i + 1] - arr[i]) for i in range(n - 1)]
    difference_arr.sort(key=lambda x: x[1], reverse=True)
    difference_arr = difference_arr[: k - 1]
    for i in range(len(difference_arr)):
        difference_arr[i] = difference_arr[i][0]

    difference_arr += [n - 1]

    s = 0
    previous_index = 0
    for i in range(len(difference_arr)):
        s += arr[difference_arr[i]] - arr[previous_index] + 1
        previous_index = difference_arr[i] + 1
    print(s)


if __name__ == "__main__":
    main()

# correct
