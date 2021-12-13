even_digits = ['0', '2', '4', '6', '8']


def driver_function(number_string):
    if number_string[-1] in even_digits:
        return 0
    elif number_string[0] in even_digits:
        return 1
    else:
        for character in number_string:
            if character in even_digits:
                return 2
        return -1


def main():
    for _ in range(int(input())):
        print(driver_function(input()))


main()

# correct
