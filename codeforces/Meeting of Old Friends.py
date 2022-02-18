from xmlrpc.client import MININT


def main():
    l1, r1, l2, r2, k = list(map(int, input().split()))

    left, right = max(l1, l2), min(r1, r2)
    minutes = right - left + 1
    if left <= k <= right:
        minutes -= 1

    if minutes <= 0:
        print(0)
    else:
        print(minutes)


if __name__ == "__main__":
    main()

# correct
