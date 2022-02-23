def main():
    n = int(input())

    a = 1

    if n == 0:
        b = 1
    else:
        rem = n % 4
        if rem == 0:
            b = 6
        elif rem == 1:
            b = 2
        elif rem == 2:
            b = 4
        else:
            b = 8

    if n == 0:
        c = 1
    else:
        rem = n % 2
        if rem == 0:
            c = 6
        else:
            c = 4

    rem = n % 4
    if rem == 0:
        d = 1
    elif rem == 1:
        d = 3
    elif rem == 2:
        d = 9
    else:
        d = 7

    answer = (a % 5 + b % 5 + c % 5 + d % 5) % 5
    print(answer)


if __name__ == "__main__":
    main()


# correct
