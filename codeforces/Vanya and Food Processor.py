def main():
    n, h, k = map(int, input().split())
    arr = list(map(int, input().split()))

    total_time = 0
    s = 0
    i = 0
    while not (s == 0 and i == n):
        while i < n and s + arr[i] <= h:
            s += arr[i]
            i += 1

        time_taken, s = divmod(s, k)
        if time_taken > 0:
            total_time += time_taken
        else:
            total_time += 1
            s = 0

    print(total_time)


if __name__ == "__main__":
    main()

# correct
