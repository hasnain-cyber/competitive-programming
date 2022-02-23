def main():
    n = int(input())

    d = 1
    s = 0
    while True:
        nNumbers = 9 * (10 ** (d - 1))
        if n - nNumbers > 0:
            n -= nNumbers
            s += d * nNumbers
        else:
            s += d * n
            break
        d += 1
    print(s)


if __name__ == "__main__":
    main()

# correct
