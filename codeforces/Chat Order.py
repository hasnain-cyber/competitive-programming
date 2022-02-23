def main():
    n = int(input())
    temp_dict = {}
    for i in range(n):
        new_entry = input()
        temp_dict[new_entry] = i

    temp_data_list = list(temp_dict.items())
    temp_data_list.sort(key=lambda x: x[1], reverse=True)
    for element in temp_data_list:
        print(element[0])


if __name__ == "__main__":
    main()

# correct
