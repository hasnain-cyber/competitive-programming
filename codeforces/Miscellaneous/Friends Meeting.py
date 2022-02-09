def main():
    x1 = int(input())
    x2 = int(input())
    d = abs(x2 - x1)
    if d % 2 == 0:
        d /= 2
        print(int(d * (d + 1)))
    else:
        d //= 2
        print((d + 1) ** 2)


if __name__ == "__main__":
    main()

# correct
