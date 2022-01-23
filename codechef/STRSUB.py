def main():
    for _ in range(int(input())):
        n, k, q = list(map(int, input().split()))
        string = input()
        temp_dict = dict()
        for i in range(len(string)):
            for j in range(i, len(string)):
                sub_string = string[i : j + 1]
                if sub_string.count("1") > k or sub_string.count("0") > k:
                    break


if __name__ == "__main__":
    main()

# could not solve
