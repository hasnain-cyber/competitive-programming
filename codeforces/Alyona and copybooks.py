def main():
    n, a, b, c = map(int, input().split())

    rem = n % 4
    answer = 0
    if rem == 0:
        answer = 0
    elif rem == 1:
        answer = min(3 * a, a + b, c)
    elif rem == 2:
        answer = min(2 * a, b, 2 * c)
    else:
        answer = min(a, b + c, 3 * c)

    print(answer)


if __name__ == "__main__":
    main()

# correct
