def main():
    k = int(input())
    string = input()

    temp_dict = dict()
    for element in string:
        if element in temp_dict:
            temp_dict[element] += 1
        else:
            temp_dict[element] = 1

    temp_string = ""
    for key, value in temp_dict.items():
        if value % k != 0:
            print(-1)
            return
        else:
            temp_string += key * (value // k)
    print(temp_string * k)


if __name__ == "__main__":
    main()

# correct
