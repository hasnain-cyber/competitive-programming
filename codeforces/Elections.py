def main():
    n, m = list(map(int, input().split()))
    arr = [list(map(int, input().split())) for _ in range(m)]

    score_list = []
    for i in range(m):
        mx = max(arr[i])
        score_list.append(arr[i].index(mx) + 1)

    temp_dict = {}
    for element in score_list:
        if element not in temp_dict:
            temp_dict[element] = 1
        else:
            temp_dict[element] += 1

    mx = max(temp_dict.values())
    print(min([key for key, value in temp_dict.items() if value == mx]))


if __name__ == "__main__":
    main()

# correct
