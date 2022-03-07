def main():
    arr = [character for character in input()]

    for _ in range(int(input())):
        l, r, k = map(int, input().split())

        temp_arr1 = [arr[i] for i in range(l - 1, r)]
        temp_arr2 = [0 for _ in range(r - l + 1)]

        for i in range(r - l + 1):
            temp_arr2[(i + k) % (r - l + 1)] = temp_arr1[i]

        for i in range(l - 1, r):
            arr[i] = temp_arr2[i - l + 1]

    print("".join(arr))


if __name__ == "__main__":
    main()

# correct
