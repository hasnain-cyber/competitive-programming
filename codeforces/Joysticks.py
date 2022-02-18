from time import sleep


def main():
    a, b = list(map(int, input().split()))

    counter = 0
    while a > 1 or b > 1:
        a, b = max(a, b), min(a, b)
        if a % 2 == 0:
            factor = a - 2
            a = 2
        else:
            factor = a - 1
            a = 1

        if factor > 0:
            counter += factor // 2
            b += factor // 2
        elif factor == 0:
            counter += 1
            break

    print(counter)


if __name__ == "__main__":
    main()

# correct
