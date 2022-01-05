def main():
    for _ in range(int(input())):
        z, y, a, b, c = list(map(int, input().split()))
        if z - y - a - b - c >= 0:
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    main()


# correct
