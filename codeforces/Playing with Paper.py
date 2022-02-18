def main():
    a, b = list(map(int, input().split()))

    counter = 0
    while a > 0 and b > 0:
        if a >= b:
            counter += a // b
            a = a % b
        else:
            counter += b // a
            b = b % a
    print(counter)


if __name__ == "__main__":
    main()

# correct
