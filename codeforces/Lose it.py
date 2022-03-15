def main():
    n = int(input())
    arr = list(map(int, input().split()))

    template_arr = [4, 8, 15, 16, 23, 42]
    counter_arr = [0, 0, 0, 0, 0, 0]

    for element in arr:
        if element == template_arr[0]:
            counter_arr[0] += 1
        elif element == template_arr[1]:
            counter_arr[1] = min(counter_arr[0], counter_arr[1] + 1)
        elif element == template_arr[2]:
            counter_arr[2] = min(counter_arr[1], counter_arr[2] + 1)
        elif element == template_arr[3]:
            counter_arr[3] = min(counter_arr[2], counter_arr[3] + 1)
        elif element == template_arr[4]:
            counter_arr[4] = min(counter_arr[3], counter_arr[4] + 1)
        elif element == template_arr[5]:
            counter_arr[5] = min(counter_arr[4], counter_arr[5] + 1)

    print(n - counter_arr[5] * 6)


if __name__ == "__main__":
    main()

# correct
