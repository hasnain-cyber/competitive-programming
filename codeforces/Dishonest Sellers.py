def main():
    n, k = map(int, input().split())
    a, b = list(map(int, input().split())), list(map(int, input().split()))

    difference_arr = []
    for i in range(n):
        difference_arr.append((a[i] - b[i], i))
    difference_arr.sort(key=lambda x: x[0])

    counter = 0
    total = 0
    for i in range(n):
        if difference_arr[i][0] <= 0:
            counter += 1
            total += a[difference_arr[i][1]]
        elif counter >= k:
            counter += 1
            total += b[difference_arr[i][1]]
        else:
            counter += 1
            total += a[difference_arr[i][1]]
    print(total)


if __name__ == "__main__":
    main()

# correct
