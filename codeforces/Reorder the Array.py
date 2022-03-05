def main():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()

    pointer1, pointer2 = 0, n // 2
    counter = 0
    while pointer1 <= n // 2 - 1 and pointer2 <= n - 1:
        if arr[pointer1] < arr[pointer2]:
            counter += 1

        pointer1 += 1
        pointer2 += 1

    if n % 2 == 1:
        counter += 1
    print(counter)


if __name__ == "__main__":
    main()

# could not solve
