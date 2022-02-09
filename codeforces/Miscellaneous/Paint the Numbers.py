def main():
    n = int(input())
    arr = list(map(lambda x: [int(x), 0], input().split()))
    arr.sort(key=lambda x: x[0])

    counter = 0
    for i in range(n):
        if arr[i][1] == 1:
            continue
        else:
            counter += 1
            for j in range(i + 1, n):
                if arr[j][1] == 1:
                    continue
                elif arr[j][0] % arr[i][0] == 0:
                    arr[j][1] = 1
    print(counter)


if __name__ == "__main__":
    main()

# correct
