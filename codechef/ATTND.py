def main():
    for _ in range(int(input())):
        n = int(input())
        names_dict = dict()

        names_list = []
        for _ in range(n):
            first_name, last_name = input().split()
            names_list.append((first_name, last_name))
            if first_name in names_dict:
                names_dict[first_name].append(last_name)
            else:
                names_dict[first_name] = [last_name]

        for first_name, last_name in names_list:
            if len(names_dict[first_name]) > 1:
                print(first_name, last_name)
            else:
                print(first_name)


if __name__ == "__main__":
    main()

# correct
