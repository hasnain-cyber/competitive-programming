def main():
    n = int(input())
    arr = list(map(int, input().split()))

    if n % 2 == 0:
        mid_index = n // 2 - 0.5
        dist1 = abs(mid_index - arr.index(1))
        dist2 = abs(mid_index - arr.index(n))
        print(int(max(dist1, dist2) - 0.5 + n // 2))
    else:
        mid_index = n // 2
        dist1 = abs(mid_index - arr.index(1))
        dist2 = abs(mid_index - arr.index(n))
        print(max(dist1, dist2) + -1 + (n + 1) // 2)


if __name__ == "__main__":
    main()

# correct
