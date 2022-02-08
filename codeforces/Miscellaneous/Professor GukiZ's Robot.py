def main():
    x1, y1 = list(map(int, input().split()))
    x2, y2 = list(map(int, input().split()))

    delta_x, delta_y = abs(x1 - x2), abs(y1 - y2)
    print(max(delta_x, delta_y))


if __name__ == "__main__":
    main()

# correct
