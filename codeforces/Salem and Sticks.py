def main():
    n = int(input())
    arr = list(map(int, input().split()))

    min_cost, min_t = 0, 1
    for element in arr:
        min_cost += max(abs(element - 1) - 1, 0)
    for t in range(2, 100):
        cost = 0
        for element in arr:
            cost += max(abs(element - t) - 1, 0)
        if cost < min_cost:
            min_cost = cost
            min_t = t

    print(min_t, min_cost)


if __name__ == "__main__":
    main()

# correct
