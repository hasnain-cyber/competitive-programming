def main():
    n, m = list(map(int, input().split()))
    k1, k2 = 0, 0
    temp = m / n
    while temp % 2 == 0:
        temp /= 2
        k1 += 1
    while temp % 3 == 0:
        temp /= 3
        k2 += 1
    if temp == 1:
        print(k1 + k2)
    else:
        print(-1)


if __name__ == "__main__":
    main()

# correct
