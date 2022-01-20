def main():
    for _ in range(int(input())):
        n, k = list(map(int, input().split()))

        arr = [i for i in range(1, n + 1)]
        temp_arr = arr[::2] + arr[1::2]
        counter = 1
        while not arr == temp_arr:
            temp_arr = temp_arr[::2] + temp_arr[1::2]
            counter += 1

        print(counter)
        # k %= counter
        # temp_arr = arr
        # for _ in range(k):
        #     temp_arr = temp_arr[::2] + temp_arr[1::2]
        # print(*temp_arr)


if __name__ == "__main__":
    main()

# tle
