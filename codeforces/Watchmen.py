def main():
    n = int(input())
    arr = [tuple(map(int, input().split())) for _ in range(n)]

    x_dict = {}
    y_dict = {}
    for element in arr:
        if element[0] in x_dict:
            x_dict[element[0]] += 1
        else:
            x_dict[element[0]] = 1

        if element[1] in y_dict:
            y_dict[element[1]] += 1
        else:
            y_dict[element[1]] = 1

    ans = 0
    for value in x_dict.values():
        ans += (value * (value - 1)) // 2
    for value in y_dict.values():
        ans += (value * (value - 1)) // 2

    identical_dict = {}
    for element in arr:
        if element in identical_dict:
            identical_dict[element] += 1
        else:
            identical_dict[element] = 1

    for values in identical_dict.values():
        ans -= (values * (values - 1)) // 2

    print(ans)


if __name__ == "__main__":
    main()

# correct
