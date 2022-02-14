def main():
    n, m = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    s, counter = 0, 0
    for i in range(n):
        if s + arr[i] > m:
            counter += 1
            s = arr[i]
        else:
            s += arr[i]
    if s > 0:
        counter += 1
    print(counter)


if __name__ == "__main__":
    main()

# correct
