def main():
    for _ in range(int(input())):
        n, x, t = list(map(int, input().split()))
        k = t // x
        if k + 1 <= n:
            answer = k * (k - 1) // 2 + (n - k) * k
            print(answer)
        else:
            print(n * (n - 1) // 2)


if __name__ == "__main__":
    main()

# correct
