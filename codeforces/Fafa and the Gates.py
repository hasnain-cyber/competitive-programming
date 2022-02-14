import math


def main():
    n = int(input())
    string = input()

    sign_arr = [0]
    current_position = (0, 0)
    for element in string:
        new_position = (
            current_position[0] + (1 if element == "R" else 0),
            current_position[1] + (1 if element == "U" else 0),
        )
        new_position_sign = new_position[1] - new_position[0]
        if new_position_sign == 0:
            sign_arr.append(0)
        elif new_position_sign > 0:
            sign_arr.append(1)
        else:
            sign_arr.append(-1)

        current_position = new_position

    counter = 0
    for i in range(len(sign_arr) - 2):
        test_arr = sign_arr[i : i + 3]
        if test_arr in [[-1, 0, 1], [1, 0, -1]]:
            counter += 1

    print(counter)


if __name__ == "__main__":
    main()

# correct
