def main():
    for _ in range(int(input())):
        n = int(input())
        number = input()

        odd_arr = []
        for digit in number:
            if int(digit) % 2 == 1:
                odd_arr.append(digit)
            if len(odd_arr) == 2:
                break

        if len(odd_arr) < 2:
            print(-1)
        else:
            print(odd_arr[0] + odd_arr[1])


if __name__ == "__main__":
    main()

# correct
