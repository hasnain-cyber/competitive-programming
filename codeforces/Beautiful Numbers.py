def check_beautiful(n, a, b):
    while n % 10 in (a, b):
        n //= 10
    return n == 0


def main():
    a, b, n = map(int, input().split())
    n_c_i_arr = [1]
    previous_numerator, previous_denominator = n, 1
    for _ in range(1, (n + 1) // 2):
        n_c_i_arr.append(n_c_i_arr[-1] * previous_numerator // previous_denominator)
        previous_numerator -= 1
        previous_denominator += 1

    counter = 0
    for i in range(n + 1):
        s = i * a + (n - i) * b
        if check_beautiful(s, a, b):
            if i < n // 2:
                counter += 2 * n_c_i_arr[i]
            else:
                counter += 2 * n_c_i_arr[n - i]
    print(counter % (10**9 + 7))


if __name__ == "__main__":
    main()

# tle
