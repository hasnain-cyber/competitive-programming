def main():
    for _ in range(int(input())):
        n, m = map(int, input().split())
        arr = list(map(int, input().split()))
        swap_arr = set(map(int, input().split()))

        temp_arr = []
        temp_temp_arr = []
        for i in range(n):
            temp_temp_arr.append(arr[i])
            if (not i + 1 in swap_arr) or i == n - 1:
                temp_arr.append(temp_temp_arr)
                temp_temp_arr = []

        final_arr = []
        for temp_temp_arr in temp_arr:
            final_arr.extend(sorted(temp_temp_arr))

        if final_arr == list(sorted(arr)):
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    main()

# correct
