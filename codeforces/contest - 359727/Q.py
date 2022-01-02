def main():
    n = int(input())
    arr = list(map(int, input().split()))

    prefix_sum_arr = [0]
    for cost in arr:
        prefix_sum_arr.append(prefix_sum_arr[-1] + cost)
    arr.sort()
    sorted_prefix_sum_arr = [0]
    for cost in arr:
        sorted_prefix_sum_arr.append(sorted_prefix_sum_arr[-1] + cost)

    for _ in range(int(input())):
        type, l, r = list(map(int, input().split()))
        if type == 1:
            print(prefix_sum_arr[r] - prefix_sum_arr[l - 1])
        else:
            print(sorted_prefix_sum_arr[r] - sorted_prefix_sum_arr[l - 1])


if __name__ == '__main__':
    main()

# correct
