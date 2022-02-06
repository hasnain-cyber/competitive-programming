def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(lambda x: int(x) % 2, input().split()))

        last_odd_index = -1
        for i in range(len(arr)):
            if arr[n - i - 1] == 1:
                last_odd_index = n - i - 1
                break

        temp_arr = []
        flag = True
        for i in range(n - 1):
            if (arr[i] % 2, arr[i + 1] % 2) not in [(0, 1), (1, 0)]:
                if last_odd_index <= i:
                    flag = False
                    break
                else:
                    temp_arr.append((i + 1, last_odd_index + 1))

        if flag:
            print(len(temp_arr))
            for i in range(len(temp_arr)):
                print(*temp_arr[i])
        else:
            print(-1)


if __name__ == "__main__":
    main()

# correct
