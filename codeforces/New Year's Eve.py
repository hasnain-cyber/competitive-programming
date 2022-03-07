def main():
    n, k = map(int, input().split())

    if k == 1:
        print(n)
    else:
        binary_n = "{0:b}".format(n)
        xor_sum = int("1" * len(binary_n), 2)
        print(xor_sum)


if __name__ == "__main__":
    main()

# correct
