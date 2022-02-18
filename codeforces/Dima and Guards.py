def main():
    n = int(input())
    arr = [list(map(int, input().split())) for _ in range(4)]

    for i in range(4):
        min_cost = min(arr[i][:2]) + min(arr[i][2:])
        if min_cost <= n:
            print(i + 1, min(arr[i][:2]), n - min(arr[i][:2]))
            return
    print(-1)


if __name__ == "__main__":
    main()

# correct
