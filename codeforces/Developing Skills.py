import math


def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    for i in range(n):
        arr[i] = (arr[i], math.ceil(arr[i] / 10) * 10 - arr[i])
    arr.sort(key=lambda x: x[1])

    s = 0
    ans = 0
    for i in range(n):
        if s + arr[i][1] <= k:
            s += arr[i][1]
            ans += math.ceil(arr[i][0] / 10)
        else:
            ans += math.floor(arr[i][0] / 10)

    ans += (k - s) // 10

    print(ans)


if __name__ == "__main__":
    main()

# wrong answer