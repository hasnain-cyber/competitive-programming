def main():
    n = int(input())
    arr = list(map(int, input().split()))

    presum_arr1 = [0]
    for i in range(n):
        presum_arr1.append(presum_arr1[-1] + arr[i])

    arr.sort()
    presum_arr2 = [0]
    for i in range(n):
        presum_arr2.append(presum_arr2[-1] + arr[i])

    for _ in range(int(input())):
        type, l, r = list(map(int, input().split()))

        if type == 1:
            print(presum_arr1[r] - presum_arr1[l - 1])
        else:
            print(presum_arr2[r] - presum_arr2[l - 1])


if __name__ == "__main__":
    main()

# correct
