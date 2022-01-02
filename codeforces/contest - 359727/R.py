def main():
    for _ in range(int(input())):
        n, x = list(map(int, input().split()))
        arr = list(map(int, input().split()))

        s = sum(arr)
        if s % x != 0:
            print(n)
        else:
            break_flag = False
            for i in range(n // 2):
                if arr[i] % x != 0 or arr[n - i - 1] % x != 0:
                    print(n - i - 1)
                    break_flag = True
                    break
            if not break_flag:
                print(-1)


if __name__ == '__main__':
    main()

# correct
