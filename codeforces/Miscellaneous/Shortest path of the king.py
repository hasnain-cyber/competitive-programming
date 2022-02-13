def convert_to_tuple(s):
    return (ord(s[0]) - ord("a"), int(s[1]) - 1)


def main():
    starting_position = convert_to_tuple(input())
    ending_position = convert_to_tuple(input())
    difference = (
        ending_position[0] - starting_position[0],
        ending_position[1] - starting_position[1],
    )

    temp_arr = []
    while difference != (0, 0):
        temp_string = ""
        if difference[0] > 0:
            temp_string += "R"
            difference = (difference[0] - 1, difference[1])
        elif difference[0] < 0:
            temp_string += "L"
            difference = (difference[0] + 1, difference[1])
        if difference[1] > 0:
            temp_string += "U"
            difference = (difference[0], difference[1] - 1)
        elif difference[1] < 0:
            temp_string += "D"
            difference = (difference[0], difference[1] + 1)
        temp_arr.append(temp_string)

    print(len(temp_arr))
    for element in temp_arr:
        print(element)


if __name__ == "__main__":
    main()

# correct
