def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        max_indices = []
        for i in range(1, n - 1):
            if arr[i - 1] < arr[i] and arr[i] > arr[i + 1]:
                max_indices.append(i)

        if len(max_indices) == 0:
            print(0)
        elif len(max_indices) == 1:
            print(1)
        else:
            distance_arr = []
            for i in range(len(max_indices) - 1):
                distance_arr.append(max_indices[i + 1] - max_indices[i])
            print(distance_arr)


if __name__ == "__main__":
    main()

# could not solve
