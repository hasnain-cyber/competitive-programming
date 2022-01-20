import math


def check_prime(num_binary):
    num = int(num_binary, 2)

    prime_flag = 0
    if num > 1:
        for i in range(2, int(math.sqrt(num)) + 1):
            if num % i == 0:
                prime_flag = 1
                break
        if prime_flag == 0:
            return True
        else:
            return False
    else:
        return False


def main():
    temp_dict = dict()

    for _ in range(int(input())):
        string = input()

        break_flag = False
        for i in range(len(string)):
            if break_flag:
                break

            if string[i] == "0":
                continue

            for j in range(i, len(string)):
                sub_string = string[i : j + 1]

                if sub_string in temp_dict:
                    check_value = temp_dict[sub_string]
                else:
                    check_value = check_prime(sub_string)
                    temp_dict[sub_string] = check_value

                if check_value:
                    break_flag = True
                    break

        temp_dict[string] = break_flag
        if break_flag:
            print("Yes")
        else:
            print("No")


if __name__ == "__main__":
    main()


# correct
