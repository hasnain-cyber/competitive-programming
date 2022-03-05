def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        arr.sort()

        l, r = 1, n - 1
        sum_l, sum_r = arr[0], 0
        flag = False
        while l < r:
            sum_l += arr[l]
            sum_r += arr[r]

            if sum_l < sum_r:
                flag = True
                break

            l += 1
            r -= 1

        print("YES" if flag else "NO")


if __name__ == "__main__":
    main()

# correct
