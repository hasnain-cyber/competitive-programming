def main():
    for _ in range(int(input())):
        a, b = list(map(int, input().split()))

        a, b = min(a, b), max(a, b)

        counter = 0
        while a > 0 and b > 0:
            divisor = b // a
            counter += divisor
            b -= divisor * a
            a, b = b, a

        print(counter)


if __name__ == "__main__":
    main()

# correct
