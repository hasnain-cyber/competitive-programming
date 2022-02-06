def main():
    for _ in range(int(input())):
        n, k = list(map(int, input().split()))
        s = input()

        counter = 0
        for i in range(n // 2):
            if s[i] != s[n - i - 1]:
                counter += 1

        if counter > k:
            print("NO")
        elif n % 2 == 1:
            print("YES")
        else:
            print("YES" if (counter - k) % 2 == 0 else "NO")


if __name__ == "__main__":
    main()

# correct
