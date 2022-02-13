def main():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()

    print(min(arr[n - 2] - arr[0], arr[n - 1] - arr[1]))


if __name__ == "__main__":
    main()

# correct
