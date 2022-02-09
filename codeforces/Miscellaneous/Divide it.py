def main():
    for _ in range(int(input())):
        n = int(input())
        d1 = 0
        d2 = 0
        d3 = 0
        while n % 2 == 0:
            n //= 2
            d1 += 1
        while n % 3 == 0:
            n //= 3
            d2 += 1
        while n % 5 == 0:
            n //= 5
            d3 += 1

        if n == 1:
            print(d1 + 2 * d2 + 3 * d3)
        else:
            print(-1)


if __name__ == "__main__":
    main()

# correct

# alternate solution - not working, don't know why

# def count_factors(x, d):
#     counter = 0
#     while x % d == 0:
#         x /= d
#         counter += 1
#     return counter


# def main():
#     for _ in range(int(input())):
#         n = int(input())
#         d1 = count_factors(n, 2)
#         d2 = count_factors(n, 3)
#         d3 = count_factors(n, 5)

#         if (2 ** d1) * (3 ** d2) * (5 ** d3) == n:
#             print(d1 + 2 * d2 + 3 * d3)
#         else:
#             print(-1)


# if __name__ == "__main__":
#     main()
