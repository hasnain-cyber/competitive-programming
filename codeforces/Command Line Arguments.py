def main():
    string = input()

    answer_arr = []
    temp_string = ""
    open_quote = False
    for character in string:
        if character == '"':
            if open_quote:
                open_quote = False
                answer_arr.append(temp_string)
                temp_string = ""
            else:
                open_quote = True
        else:
            if open_quote:
                temp_string += character
            else:
                if not character == " ":
                    temp_string += character
                else:
                    if temp_string != "":
                        answer_arr.append(temp_string)
                        temp_string = ""

    if temp_string != "":
        answer_arr.append(temp_string)

    for element in answer_arr:
        print(f"<{element}>")


if __name__ == "__main__":
    main()

# correct
