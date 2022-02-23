def main():
    string = input()

    answer_string = ""
    for index, value in enumerate(string):
        if index == 0 and value == "9":
            answer_string += "9"
        else:
            if int(value) >= 5:
                answer_string += str(9 - int(value))
            else:
                answer_string += value
    print(answer_string)


if __name__ == "__main__":
    main()

# correct
