def main():
    n = int(input())

    i = 2
    while i**2 <= n:
        while n % (i**2) == 0:
            n //= i
        i += 1

    print(n)


if __name__ == "__main__":
    main()

# correct
