def main():
    n, m = list(map(int, input().split()))
    if n % 2 == 0:
        answer = (n // 2) * m
    elif m % 2 == 0:
        answer = (m // 2) * n
    else:
        answer = (n // 2) * m + (m // 2)
    print(answer)


if __name__ == "__main__":
    main()

# correct
