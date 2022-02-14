def main():
    k = int(input())
    arr = list(map(int, input().split()))
    arr.sort()

    if k == 0:
        print(0)
        return
    if sum(arr) < k:
        print(-1)

    s = 0
    for i in range(len(arr)):
        value = arr[len(arr) - i - 1]
        s += value
        if s >= k:
            print(i + 1)
            return


if __name__ == "__main__":
    main()

# correct
