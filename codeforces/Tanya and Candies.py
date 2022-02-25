def main():
    n = int(input())
    arr = list(map(int, input().split()))

    prefix_even_sum, prefix_odd_sum = [0], [0]
    for i in range(n):
        if i % 2 == 0:
            prefix_even_sum.append(prefix_even_sum[-1] + arr[i])
        else:
            prefix_odd_sum.append(prefix_odd_sum[-1] + arr[i])

    counter = 0
    for i in range(n):
        if i % 2 == 0:
            k = i // 2
            pre_opp_sum = prefix_odd_sum[k]
            suff_same_sum = prefix_even_sum[-1] - prefix_even_sum[k + 1]
            pre_same_sum = prefix_even_sum[k]
            suff_opp_sum = prefix_odd_sum[-1] - prefix_odd_sum[k]
        else:
            k = (i - 1) // 2
            pre_opp_sum = prefix_even_sum[k + 1]
            suff_same_sum = prefix_odd_sum[-1] - prefix_odd_sum[k + 1]
            pre_same_sum = prefix_odd_sum[k]
            suff_opp_sum = prefix_even_sum[-1] - prefix_even_sum[k + 1]

        if pre_opp_sum + suff_same_sum == suff_opp_sum + pre_same_sum:
            counter += 1

    print(counter)


if __name__ == "__main__":
    main()

# correct
