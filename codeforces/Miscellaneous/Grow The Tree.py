def main():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()

    if n % 2 == 0:
        horizontal, vertical = sum(arr[: n // 2]), sum(arr[n // 2 :])
        print(horizontal ** 2 + vertical ** 2)
    else:
        horizontal, vertical = sum(arr[: n // 2]), sum(arr[n // 2 + 1 :])
        print(
            max(
                (horizontal + arr[n // 2]) ** 2 + vertical ** 2,
                horizontal ** 2 + (vertical + arr[n // 2]) ** 2,
            )
        )


if __name__ == "__main__":
    main()

# correct
