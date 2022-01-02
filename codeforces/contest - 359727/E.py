def main():
    for _ in range(int(input())):
        a, k = tuple(map(int, input().split()))

        if a <= k:
            print(k - a)
        else:
            if (a - k) % 2 == 0:
                print(0)
            else:
                print(1)


if __name__ == "__main__":
    main()

# correct
