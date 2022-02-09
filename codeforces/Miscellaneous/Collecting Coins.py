def main():
    for _ in range(int(input())):
        a, b, c, n = list(map(int, input().split()))

        k = (a + b + c + n) / 3
        if k.is_integer() and max(a, b, c, k) == k:
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    main()

# correct
