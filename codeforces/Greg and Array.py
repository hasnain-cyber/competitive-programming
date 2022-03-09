def main():
    n, m, k = map(int, input().split())
    arr = list(map(int, input().split()))

    operations_arr = [tuple(map(int, input().split())) for _ in range(m)]  # l, r, d
    application_arr = [tuple(map(int, input().split())) for _ in range(k)]  # x, y

    application_dict = {}
    for element in application_arr:
        if element in application_dict:
            application_dict[element] += 1
        else:
            application_dict[element] = 1

    operations_application_dict = {}
    for key, value in application_dict.items():
        for operation in operations_arr[key[0] - 1 : key[1]]:
            if operation in operations_application_dict:
                operations_application_dict[operation] += value
            else:
                operations_application_dict[operation] = value

    for key, value in operations_application_dict.items():
        l, r, d = key
        for i in range(l - 1, r):
            arr[i] += d * value

    print(*arr)


if __name__ == "__main__":
    main()

# tle
