def main():
    n = int(input())
    arr = list(map(int, input().split()))

    value1, value2 = min(arr), max(arr)
    count1, count2 = arr.count(value1), arr.count(value2)

    if value1 == value2:
        print(0, (count1 * (count1 - 1)) // 2)
    else:
        print(value2 - value1, count1 * count2)


if __name__ == "__main__":
    main()

# correct
