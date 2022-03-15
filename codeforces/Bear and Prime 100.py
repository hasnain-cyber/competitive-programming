from sys import stdout


def primes(n):
    # Returns  a list of primes < n
    sieve = [True] * n
    for i in range(3, int(n**0.5) + 1, 2):
        if sieve[i]:
            sieve[i * i :: 2 * i] = [False] * ((n - i * i - 1) // (2 * i) + 1)
    return [2] + [i for i in range(3, n, 2) if sieve[i]]


def main():
    primes_arr = primes(51)

    temp_arr1 = []
    for element in primes_arr:
        if element**2 > 100:
            break
        else:
            print(element**2)
            stdout.flush()
            temp_arr1.append(input())

    if "yes" in temp_arr1:
        print("composite")
        exit()
    else:
        temp_arr2 = []
        for element in primes_arr:
            if element < 50:
                print(element)
                stdout.flush()
                temp_arr2.append(input())
            else:
                break

        if temp_arr2.count("yes") >= 2:
            print("composite")
        else:
            print("prime")

        exit()


if __name__ == "__main__":
    main()

# correct
