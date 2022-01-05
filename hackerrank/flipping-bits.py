def main():
    for _ in range(int(input())):
        n = int(input())
        binary_string = "{:032b}".format(n)

        flipped_binary_string = ""
        for bit in binary_string:
            flipped_binary_string += "1" if bit == "0" else "0"
        print(int(flipped_binary_string, 2))


if __name__ == "__main__":
    main()


# correct
