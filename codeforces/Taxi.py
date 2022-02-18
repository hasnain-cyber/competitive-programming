import math


def main():
    n = int(input())
    arr = list(map(int, input().split()))

    temp_dict = {1: 0, 2: 0, 3: 0, 4: 0}
    for element in arr:
        temp_dict[element] += 1

    counter = 0

    # handle 4 people
    counter += temp_dict[4]
    temp_dict[4] = 0

    # handle 2 people
    counter += temp_dict[2] // 2
    temp_dict[2] %= 2

    # handle 1 and 3 people
    if temp_dict[1] > temp_dict[3]:
        temp_dict[1] -= temp_dict[3]
        counter += temp_dict[3]
        temp_dict[3] = 0
    else:
        counter += temp_dict[3]
        temp_dict[3] = 0
        temp_dict[1] = 0

    temp = temp_dict[1] + 2 * temp_dict[2]
    counter += math.ceil(temp / 4)

    print(counter)


if __name__ == "__main__":
    main()

# correct
