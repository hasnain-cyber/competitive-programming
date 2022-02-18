def main():
    n = int(input())
    arr = list(map(int, input().split()))

    mn = min(arr)
    mn_indices = [i for i in range(n) if arr[i] == mn]

    mn_distance = n - 1
    for i in range(len(mn_indices) - 1):
        mn_distance = min(mn_distance, mn_indices[i + 1] - mn_indices[i])

    print(mn_distance)


if __name__ == "__main__":
    main()

# correct
