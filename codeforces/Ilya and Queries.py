def main():
    string = input()
    presum_arr = [0]
    for i in range(len(string) - 1):
        if string[i] == string[i + 1]:
            presum_arr.append(presum_arr[-1] + 1)
        else:
            presum_arr.append(presum_arr[-1])

    for _ in range(int(input())):
        l, r = list(map(int, input().split()))

        print(presum_arr[r - 1] - presum_arr[l - 1])


if __name__ == "__main__":
    main()

# correct
