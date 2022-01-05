def main():
    n, m = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    product = 1
    for i in range(n - 1):
        for j in range(i + 1, n):
            product *= abs(arr[i] - arr[j])
    print(product % m)


if __name__ == "__main__":
    main()

# could not solve
