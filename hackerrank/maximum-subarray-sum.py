def main():
    for _ in range(int(input())):
        n, m = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))

        max_value = -1
        for i in range(n):
            for j in range(i, n):
                sub_arr = arr[i : j + 1]
                value = sum(sub_arr) % m
                if value > max_value:
                    max_value = value
        print(max_value)


if __name__ == "__main__":
    main()

# tle
