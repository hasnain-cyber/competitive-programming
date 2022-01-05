def main():
    for _ in range(int(input())):
        n, x, y = list(map(int, input().split()))
        cx, cy = (n + 1) // 2, (n + 1) // 2

        dif_x, dif_y = abs(cx - x), abs(cy - y)
        answer = abs(dif_x - dif_y)
        print(answer % 2)


if __name__ == "__main__":
    main()

# correct
