def convert_number_to_pattern(n):
    answer = 0

    i = 0
    while n > 0:
        rem = n % 2
        answer += rem * (10**i)
        n = n // 10
        i += 1

    return answer


def main():
    temp_dict = {}
    for _ in range(int(input())):
        type, value = input().split()
        value = int(value)

        if type == "+":
            pattern = convert_number_to_pattern(value)
            if pattern in temp_dict:
                temp_dict[pattern] += 1
            else:
                temp_dict[pattern] = 1
        elif type == "-":
            pattern = convert_number_to_pattern(value)
            temp_dict[pattern] -= 1
        else:
            print(temp_dict.get(value, 0))


if __name__ == "__main__":
    main()

# tle because of python, else the solution is correct, and working in cpp.
