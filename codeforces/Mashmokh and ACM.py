def primeFactors(n):
    return_dict = {}

    c = 2
    while n > 1:

        if n % c == 0:
            if c in return_dict:
                return_dict[c] += 1
            else:
                return_dict[c] = 1
            n = n / c
        else:
            c = c + 1

    return return_dict


def solve(current_value, k, counter, remaining_factors_dict):
    pass


def main():
    n, k = map(int, input().split())
    factors_dict = primeFactors(n)

    print(solve(n, k, 0, factors_dict))


if __name__ == "__main__":
    main()

# could not solve
