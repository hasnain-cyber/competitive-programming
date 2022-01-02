def prime_factors(n):
    i = 2
    factors = dict()
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            if i in factors:
                factors[i] += 1
            else:
                factors[i] = 1
    if n > 1:
        if n in factors:
            factors[n] += 1
        else:
            factors[n] = 1
    return factors


def main():
    for _ in range(int(input())):
        number = int(input())
        factors = prime_factors(number)

        if len(factors) == 1:
            if sum(list(factors.values())) >= 6:
                print('YES')
                temp_value = list(factors.keys())[0]
                print(temp_value, temp_value ** 2, number // temp_value // temp_value ** 2)
            else:
                print('NO')
        elif len(factors) == 2:
            if sum(list(factors.values())) >= 4:
                temp_list = list(factors.keys())[0:2]
                print('YES')
                print(temp_list[0], temp_list[1], number // temp_list[0] // temp_list[1])
            else:
                print('NO')
        else:
            temp_list = list(factors.keys())[0:2]
            print('YES')
            print(temp_list[0], temp_list[1], number // temp_list[0] // temp_list[1])


if __name__ == "__main__":
    main()

# correct
