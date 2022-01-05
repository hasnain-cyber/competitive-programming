def main():
    n = int(input())

    if n == 0:
        print(1)
    else:
        counter = 0
        binary_form = "{0:b}".format(n)
        for bit in binary_form:
            if bit == "0":
                counter += 1
        print(2 ** counter)


if __name__ == "__main__":
    main()

# correct
