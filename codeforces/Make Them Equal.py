def d2(arr):
    d = arr[-1] - arr[0]
    required_value = arr[0] + d
    for i in range(1, len(arr)):
        if required_value not in (arr[i] - d, arr[i], arr[i] + d):
            print(-1)
            return
    print(d)


def main():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()

    d = (arr[-1] - arr[0]) / 2

    if d.is_integer():
        d = int(d)
        flag = True
        required_value = arr[0] + d
        for i in range(1, n):
            if required_value not in (arr[i] - d, arr[i], arr[i] + d):
                flag = False
                break
        if flag:
            print(d)
        else:
            d2(arr)
    else:
        d2(arr)


if __name__ == "__main__":
    main()

# correct
