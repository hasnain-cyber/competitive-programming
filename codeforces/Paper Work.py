def main():
    n = int(input())
    arr = list(map(int, input().split()))

    counter = 0
    total_counter_arr = []
    for index, value in enumerate(arr):
        if value < 0:
            counter += 1
        if counter == 3:
            counter = 1
            s = sum(total_counter_arr)
            total_counter_arr.append(index - s)
    s = sum(total_counter_arr)
    if s < n:
        total_counter_arr.append(n - s)
    print(len(total_counter_arr))
    print(*total_counter_arr)


if __name__ == "__main__":
    main()

# correct
