def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        flag = True
        while flag:
            flag = False
            for i in range(n):
                for j in range(i + 1, n):
                    x = arr[i] | arr[j]
                    if x < arr[i] + arr[j]:
                        arr[i] = x
                        arr[j] = 0
                        flag = True

        print(sum(arr))


if __name__ == "__main__":
    main()

# correct
