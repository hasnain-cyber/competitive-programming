def main():
    n, p = list(map(int, input().split()))
    string = input()

    replacement_cost_arr = [0] * n
    for i in range(n // 2):
        difference = min(
            abs(ord(string[i]) - ord(string[-i - 1])),
            abs(26 - abs(ord(string[i]) - ord(string[-i - 1]))),
        )
        replacement_cost_arr[i] = difference
        replacement_cost_arr[-i - 1] = difference

    current_cursor_pos = p
    total_cost = 0
    for i in range(n // 2):
        if replacement_cost_arr[i] == 0:
            continue
        travel_cost_1 = min(
            abs(current_cursor_pos - i - 1), n - current_cursor_pos + i + 1
        )
        travel_cost_2 = min(abs(current_cursor_pos + i - n), i + current_cursor_pos)

        if travel_cost_1 <= travel_cost_2:
            total_cost += travel_cost_1 + replacement_cost_arr[i]
            current_cursor_pos = i + 1
        else:
            total_cost += travel_cost_2 + replacement_cost_arr[i]
            current_cursor_pos = n - i
        print(total_cost)
    print(total_cost)


if __name__ == "__main__":
    main()

# could not solve
