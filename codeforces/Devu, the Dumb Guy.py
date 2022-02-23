def main():
    n, x = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    arr.sort()

    s = 0
    for i in range(n):
        s += arr[i] * x
        x = max(1, x - 1)
    print(s)


if __name__ == "__main__":
    main()

# correct
