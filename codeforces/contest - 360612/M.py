def main():
    n = int(input())
    arr = list(map(int, input().split()))

    s = sum(arr) / 3
    prefix_sum_arr = [0]
    for element in arr:
        prefix_sum_arr.append(prefix_sum_arr[-1] + element)

    if s.is_integer():
        counter, answer = 0, 0
        for i in range(1, n):
            if prefix_sum_arr[i] == 2 * s:
                answer += counter
            if prefix_sum_arr[i] == s:
                counter += 1
        print(answer)
    else:
        print(0)


if __name__ == "__main__":
    main()

# correct
