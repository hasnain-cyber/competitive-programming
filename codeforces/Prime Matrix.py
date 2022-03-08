def primes(n):
    # Returns  a list of primes < n
    sieve = [True] * n
    for i in range(3, int(n**0.5) + 1, 2):
        if sieve[i]:
            sieve[i * i :: 2 * i] = [False] * ((n - i * i - 1) // (2 * i) + 1)
    return [2] + [i for i in range(3, n, 2) if sieve[i]]


def upper_bound_binary_search(arr, x):
    l, r = 0, len(arr) - 1
    while l <= r:
        mid = (l + r) // 2
        if arr[mid] >= x:
            r = mid - 1
        else:
            l = mid + 1
    return l


def main():
    primes_arr = primes(10**5 + 4)

    n, m = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(n)]

    min_cost = float("inf")
    for i in range(n):
        cost_row = 0
        for j in range(m):
            prime_number = primes_arr[upper_bound_binary_search(primes_arr, arr[i][j])]
            cost_row += prime_number - arr[i][j]
        min_cost = min(min_cost, cost_row)

    for j in range(m):
        cost_column = 0
        for i in range(n):
            prime_number = primes_arr[upper_bound_binary_search(primes_arr, arr[i][j])]
            cost_column += prime_number - arr[i][j]
        min_cost = min(min_cost, cost_column)

    print(min_cost)


if __name__ == "__main__":
    main()

# correct, submit using pypy.
