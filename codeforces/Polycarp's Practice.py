def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    sorted_arr_max = list(sorted(arr))[-k:]

    temp_dict = {}
    for element in sorted_arr_max:
        if element in temp_dict:
            temp_dict[element] += 1
        else:
            temp_dict[element] = 1

    max_indices = []
    for i in range(n):
        if arr[i] in temp_dict and temp_dict[arr[i]] > 0:
            max_indices.append(i)
            temp_dict[arr[i]] -= 1

    answer_arr = [max_indices[0] + 1]
    for i in range(1, len(max_indices) - 1):
        answer_arr.append(max_indices[i] - max_indices[i - 1])
    if len(max_indices) > 1:
        answer_arr.append(n - sum(answer_arr))

    print(sum(sorted_arr_max))
    print(*answer_arr)


if __name__ == "__main__":
    main()

# suppose the largest elements [2,2,3,3], it will give bugs when finding the index of these.
# wrong answer
