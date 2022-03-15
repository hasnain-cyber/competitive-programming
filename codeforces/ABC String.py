def main():
    for _ in range(int(input())):
        string = input()
        length = len(string)

        if string[0] == string[-1] or length % 2 == 1:
            print("NO")
        else:
            flag1 = string.count(string[0]) == length // 2
            flag2 = string.count(string[-1]) == length // 2

            if flag1 and flag2:
                print("YES")
            elif not flag1 and not flag2:
                print("NO")
            else:
                converted_string = ""
                if string.count(string[0]) > string.count(string[-1]):
                    for i in range(length):
                        if string[i] == string[0]:
                            converted_string += "("
                        else:
                            converted_string += ")"
                else:
                    for i in range(length):
                        if string[i] == string[-1]:
                            converted_string += ")"
                        else:
                            converted_string += "("

                counter1, counter2 = 0, 0
                flag = True
                for character in converted_string:
                    if character == "(":
                        counter1 += 1
                    else:
                        counter2 += 1

                    if counter1 < counter2:
                        flag = False
                        break

                print("YES" if flag else "NO")


if __name__ == "__main__":
    main()

# wrong answer
