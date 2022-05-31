def main():
    for _ in range(int(input())):
        n, k = map(int, input().split())
        string = "{0:b}".format(k)
        n = len(string)

        last_one_index = string.rfind("1")
        answer_arr = []
        for i in range(n-1,-1,-1):
            if string[i] == '1':
                string_left, string_right = string[:i], string[i + 1 :]
                ones_left = string_left.count("1")
                
                if i == last_one_index:
                    answer_arr.append((ones_left + 1) * )


if __name__ == "__main__":
    main()
