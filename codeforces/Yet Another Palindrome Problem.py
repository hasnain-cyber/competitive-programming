def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        flag = False
        for i in range(n - 2):
            if flag:
                break
            for j in range(i + 2, n):
                if arr[i] == arr[j]:
                    flag = True
                    break

        print("YES" if flag else "NO")


if __name__ == "__main__":
    main()

# correct
