def main():
    n = int(input())

    counter = 0
    check_number = 19
    while True:
        s = 0
        temp_number = check_number
        while temp_number > 0:
            s += temp_number % 10
            temp_number //= 10

        if s == 10:
            counter += 1

        if counter == n:
            print(check_number)
            return

        check_number += 9


if __name__ == "__main__":
    main()

# correct
