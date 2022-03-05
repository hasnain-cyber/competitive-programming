def main():
    n = int(input())
    arr = list(map(int, input().split()))

    temp_dict = {}
    min_distance, max_occurance, min_distance_l, min_distance_r = (
        float("inf"),
        float("-inf"),
        0,
        0,
    )
    for index, element in enumerate(arr):
        if element in temp_dict:
            temp_dict[element].append(index + 1)
        else:
            temp_dict[element] = [index + 1]

        if len(temp_dict[element]) > max_occurance:
            max_occurance = len(temp_dict[element])

            l = temp_dict[element][0]
            r = temp_dict[element][-1]
            distance = r - l + 1

            min_distance = distance
            min_distance_l = l
            min_distance_r = r
        elif len(temp_dict[element]) == max_occurance:
            l = temp_dict[element][0]
            r = temp_dict[element][-1]
            distance = r - l + 1

            if distance < min_distance:
                min_distance = distance
                min_distance_l = l
                min_distance_r = r

    print(min_distance_l, min_distance_r)


if __name__ == "__main__":
    main()

# correct
