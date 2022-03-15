def main():
    for _ in range(int(input())):
        n, l = map(int, input().split())
        arr = list(map(lambda x: "{0:b}".format(int(x)), input().split()))

        max_length = 0
        for element in arr:
            max_length = max(max_length, len(element))

        for i in range(n):
            arr[i] = arr[i].zfill(max_length)

        y = ""
        for i in range(max_length):
            count_zero = 0
            count_one = 0
            for j in range(n):
                if arr[j][i] == "0":
                    count_zero += 1
                else:
                    count_one += 1

            if count_zero > count_one:
                y += "0"
            else:
                y += "1"
        print(int(y, 2))


if __name__ == "__main__":
    main()

# correct
