def is_prime(x):
    if x > 1:
        for i in range(2, x // 2 + 1):
            if (x % i) == 0:
                return False
        else:
            return True
    else:
        return False


def main():
    n = int(input())
    for x in range(2, n):
        if not is_prime(x) and not is_prime(n - x):
            print(x, n - x)
            break


if __name__ == "__main__":
    main()

# correct
