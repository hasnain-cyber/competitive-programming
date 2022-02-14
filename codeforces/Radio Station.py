def main():
    n, m = list(map(int, input().split()))

    ip_map = {}
    for _ in range(n):
        temp = input().split()
        ip_map[temp[1]] = temp[0]

    for _ in range(m):
        temp = input().split()
        print(temp[0], temp[1], f"#{ip_map[temp[1][:-1]]}")


if __name__ == "__main__":
    main()

# correct
