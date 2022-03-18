def primes(n):
    # Returns  a list of primes < n
    sieve = [True] * n
    for i in range(3, int(n**0.5) + 1, 2):
        if sieve[i]:
            sieve[i * i :: 2 * i] = [False] * ((n - i * i - 1) // (2 * i) + 1)
    return [2] + [i for i in range(3, n, 2) if sieve[i]]


def main():
    n = int(input())

    primes_arr = primes(n + 1)

    answer_dict = {i: -1 for i in range(2, n + 1)}
    counter = 0
    current_value = 1
    for prime in primes_arr:
        for i in range(prime, n + 1, prime):
            answer_dict[i] = current_value
            counter += 1
        current_value += 1

    for i in range(2, n + 1):
        print(answer_dict[i], end=" ")


if __name__ == "__main__":
    main()

# correct
