def dfs(x, current_arr, test_dict):
    if len(test_dict) == 0:
        return current_arr

    if 2 * x in test_dict:
        temp_dict = test_dict.copy()
        temp_dict[2 * x] -= 1
        if temp_dict[2 * x] == 0:
            del temp_dict[2 * x]
        return dfs(2 * x, current_arr + [2 * x], temp_dict)
    if float(x / 3).is_integer() and x // 3 in test_dict:
        temp_dict = test_dict.copy()
        temp_dict[x // 3] -= 1
        if temp_dict[x // 3] == 0:
            del temp_dict[x // 3]
        return dfs(x // 3, current_arr + [x // 3], temp_dict)

    return None


def main():
    n = int(input())
    arr = list(map(int, input().split()))

    main_dict = {}
    for e in arr:
        if e in main_dict:
            main_dict[e] += 1
        else:
            main_dict[e] = 1

    for key in main_dict:
        temp_dict = main_dict.copy()
        temp_dict[key] -= 1
        if temp_dict[key] == 0:
            del temp_dict[key]
        result = dfs(key, [key], temp_dict)
        if result is not None:
            print(*result)
            return


if __name__ == "__main__":
    main()

# correct
