def main():
    n = int(input())
    arr = list(map(int, input().split()))

    counter = 0
    mx, mn = arr[0], arr[0]
    for i in range(1, n):
        if arr[i] > mx:
            counter += 1
            mx = arr[i]
        elif arr[i] < mn:
            counter += 1
            mn = arr[i]
    print(counter)


if __name__ == "__main__":
    main()

# correct
