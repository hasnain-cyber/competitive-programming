import math


def divisors(n):
    return_arr = []

    i = 1
    while i <= math.sqrt(n):
        if n % i == 0:

            if n / i == i:
                return_arr.append(i)
            else:
                return_arr.append(i)
                return_arr.append(int(n / i))
        i += 1

    return return_arr


def main():
    n = int(input())
    arr = list(map(int, input().split()))

    nodes_arr = list(filter(lambda x: x >= 3, divisors(n)))

    mx_value = float("-inf")
    for option in nodes_arr:
        jump_value = n // option
        for starting_point in range(0, jump_value):
            s = 0
            for i in range(starting_point, n, jump_value):
                s += arr[i]
            mx_value = max(s, mx_value)
    print(mx_value)


if __name__ == "__main__":
    main()

# correct
