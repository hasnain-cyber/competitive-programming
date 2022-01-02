def main():
    arr = []
    for _ in range(int(input())):
        arr.append(tuple(map(int, input().split())))
    arr.sort(key=lambda x: [x[0], x[1]])

    last_date = arr[0][1]
    for key, value in arr:
        if value >= last_date:
            last_date = value
        else:
            last_date = key
    print(last_date)


if __name__ == "__main__":
    main()

# correct
