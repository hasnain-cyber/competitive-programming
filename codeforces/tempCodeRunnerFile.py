def main():
    for _ in range(int(input())):
        n, s = map(int, input().split())

        ans = 0
        for i in range(0, n + 2):
            value = (i + 1) * (n**2) - 1 - i * (n - 1)
            if value >= s:
                ans = i
                break
        print(ans)


if __name__ == "__main__":
    main()
