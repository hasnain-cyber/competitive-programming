def main():
    a, b = list(map(int, input().split()))
    x, y, z = list(map(int, input().split()))

    yellow_crystals_required = 2 * x + y
    blue_crystals_required = y + 3 * z

    total = max(0, yellow_crystals_required - a) + max(0, blue_crystals_required - b)
    print(total)


if __name__ == "__main__":
    main()

# correct
