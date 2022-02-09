def main():
    k, r = list(map(int, input().split()))

    x = 1
    n1 = -1
    while True:
        value = (10 * x) / k
        if value.is_integer():
            n1 = value
            break
        else:
            x += 1

    x = 0
    while True:
        value = (10 * x + r) / k
        if value >= n1:
            print(int(n1))
            return
        if value.is_integer():
            print(int(value))
            return
        else:
            x += 1


if __name__ == "__main__":
    main()

# correct
