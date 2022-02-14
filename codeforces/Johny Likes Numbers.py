def main():
    n, k = list(map(int, input().split()))

    d = n // k
    print(k * (d + 1))


if __name__ == "__main__":
    main()

# correct
