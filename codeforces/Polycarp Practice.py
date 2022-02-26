def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    if k == 1:
        print(max(arr))
        print(n)
    else:
        k_max_elements = list(sorted(arr))[-k:]

        temp_dict = {}
        for element in k_max_elements:
            if element in temp_dict:
                temp_dict[element] += 1
            else:
                temp_dict[element] = 1

        max_indices = []
        for i in range(n):
            if arr[i] in temp_dict and temp_dict[arr[i]] > 0:
                max_indices.append(i)
                temp_dict[arr[i]] -= 1

        print(sum(k_max_elements))
        answer_arr = []
        for i in range(len(max_indices)):
            if i == 0:
                answer_arr.append(max_indices[i] + 1)
            elif i == len(max_indices) - 1:
                answer_arr.append(n - max_indices[i - 1] - 1)
            else:
                answer_arr.append(max_indices[i] - max_indices[i - 1])

        print(*answer_arr)


if __name__ == "__main__":
    main()

# correct
