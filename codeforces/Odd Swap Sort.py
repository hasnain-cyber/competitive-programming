def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        sorted_arr = list(sorted(arr))

        flag = True
        while arr != sorted_arr:
            if not flag:
                break
            for i in range(n - 1):
                if arr[i] > arr[i + 1]:
                    if arr[i] % 2 == arr[i + 1] % 2:
                        flag = False
                        break
                    else:
                        arr[i], arr[i + 1] = arr[i + 1], arr[i]
        print("YES" if flag else "NO")


if __name__ == "__main__":
    main()

# correct
