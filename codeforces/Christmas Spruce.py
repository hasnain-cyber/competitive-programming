def main():
    n = int(input())
    temp_dict = {}

    for i in range(1, n):
        parent, child = int(input()), i + 1

        if parent in temp_dict:
            temp_dict[parent].append(child)
        else:
            temp_dict[parent] = [child]

    flag = True
    for values in temp_dict.values():
        check_flag = False
        counter = 0
        for value in values:
            if value not in temp_dict:
                counter += 1
            if counter == 3:
                check_flag = True
                break
        if not check_flag:
            flag = False
            break

    if flag:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()

# correct