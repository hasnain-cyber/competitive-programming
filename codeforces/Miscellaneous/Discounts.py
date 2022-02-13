def main():
    n = int(input())
    arr = list(map(int, input().split()))
    d = int(input())
    discounts = list(map(int, input().split()))

    arr.sort()
    s = sum(arr)
    for element in discounts:
        print(s - arr[n - element])


if __name__ == "__main__":
    main()

# correct
