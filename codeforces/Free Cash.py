def main():
    n = int(input())
    temp_dict = dict()

    for _ in range(n):
        value = input()
        if value in temp_dict:
            temp_dict[value] += 1
        else:
            temp_dict[value] = 1

    print(max(temp_dict.values()))


if __name__ == "__main__":
    main()

# correct
