def find_lowest_power(k, l):
    ans = 0
    current_value = 1
    while current_value < l:
        current_value *= k
        ans += 1
    return ans


def main():
    l, r, k = map(int, input().split())

    low = find_lowest_power(k, l)
    if pow(k, low) > r:
        print(-1)
    else:
        current_value = pow(k, low)
        while current_value <= r:
            print(current_value, end=" ")
            current_value *= k


if __name__ == "__main__":
    main()
