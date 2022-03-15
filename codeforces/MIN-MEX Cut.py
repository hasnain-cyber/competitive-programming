def main():
    for _ in range(int(input())):
        string = input()

        if "0" not in string:
            print(0)
        elif "1" not in string:
            print(1)
        else:
            start_index, end_index = string.find("0"), string.rfind("0")

            flag = True
            for i in range(start_index, end_index + 1):
                if string[i] == "1":
                    flag = False
                    break

            print(1 if flag else 2)


if __name__ == "__main__":
    main()


# correct
