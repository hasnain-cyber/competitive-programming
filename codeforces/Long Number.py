def main():
    length = int(input())
    number = [int(digit) for digit in input()]
    function_map = list(map(int, input().split()))

    start_flag = False
    previously_started_flag = False
    answer_string = ""
    for digit in number:
        if digit < function_map[digit - 1]:
            if start_flag:
                answer_string += str(function_map[digit - 1])
            else:
                if previously_started_flag:
                    answer_string += str(digit)
                else:
                    start_flag = True
                    previously_started_flag = True
                    answer_string += str(function_map[digit - 1])
        elif digit == function_map[digit - 1]:
            answer_string += str(digit)
        else:
            if start_flag:
                start_flag = False
            answer_string += str(digit)

    print(answer_string)


if __name__ == "__main__":
    main()

# correct but very messy solution
