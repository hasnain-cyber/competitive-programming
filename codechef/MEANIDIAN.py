def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        arr.sort()
        median = arr[(n + 1) // 2 - 1]
        mean = sum(arr) / n

        while not mean == median:
            difference = mean - median
            if difference > 0:
                median += difference
            mean += difference / n


if __name__ == "__main__":
    main()

# could not solve
