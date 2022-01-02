def main():
    for _ in range(int(input())):
        s = input()

        max_length = 0
        counter = 0
        for character in s:
            if character == 'L':
                counter += 1
            else:
                max_length = max(max_length, counter)
                counter = 0
        max_length = max(max_length, counter)
        print(max_length + 1)


if __name__ == '__main__':
    main()

# correct
