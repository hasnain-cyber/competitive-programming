def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        mArr = []
        for i in range(n - 1):
            small, large = min(arr[i], arr[i + 1]), max(arr[i], arr[i + 1])
            if large - small > 1:
                mArr.append((small + 1, large - 1))
            else:
                mArr.append((-1, -1))
        print(mArr)


if __name__ == "__main__":
    main()

# could not solve
