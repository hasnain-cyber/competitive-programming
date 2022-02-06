def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))

        aMod, bMod = [], []
        for i in range(n):
            mn, mx = min(a[i], b[i]), max(a[i], b[i])
            aMod.append(mn)
            bMod.append(mx)

        print(max(aMod) * max(bMod))


if __name__ == "__main__":
    main()

# correct
