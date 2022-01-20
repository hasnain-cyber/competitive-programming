# function to return list of prime factors of a number
def primeFactors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return len(set(factors))


def main():
    for _ in range(int(input())):
        width, height = list(map(int, input().split()))
        if height < 2:
            print(0)
        else:
            k = primeFactors(height)
            for i in range(0, k + 1):
                factor = k - i
                if width % factor == 0:
                    print(factor)
                    break


if __name__ == "__main__":
    main()


# correct
