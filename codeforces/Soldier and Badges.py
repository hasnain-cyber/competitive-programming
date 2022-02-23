def main():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    s0 = sum(arr)

    for i in range(1, n):
        if arr[i] <= arr[i - 1]:
            arr[i] = arr[i - 1] + 1
    print(sum(arr) - s0)


if __name__ == "__main__":
    main()

# correct
