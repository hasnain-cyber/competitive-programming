import math


def main():
    n, t, k, d = list(map(int, input().split()))

    # time taken using only one oven
    time1 = math.ceil(n / k) * t

    # if we can set up the second oven and produce its first batch, then it is worth it.
    if d + t < time1:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()

# correct
