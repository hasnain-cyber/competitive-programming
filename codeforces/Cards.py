def main():
    n = int(input())
    temp_arr = list(map(int, input().split()))
    arr = []
    for i in range(n):
        element = temp_arr[i]
        arr.append((i + 1, element))
    arr.sort(key=lambda x: x[1])

    for i in range(n // 2):
        print(arr[i][0], arr[n - i - 1][0])


if __name__ == "__main__":
    main()

# correct
