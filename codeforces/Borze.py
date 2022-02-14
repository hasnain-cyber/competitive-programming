def main():
    string = input()

    i = 0
    answer = ""
    while i < len(string):
        if string[i] == ".":
            answer += "0"
            i += 1
        elif string[i] == "-":
            if string[i + 1] == ".":
                answer += "1"
            else:
                answer += "2"
            i += 2
    print(answer)


if __name__ == "__main__":
    main()

# correct
