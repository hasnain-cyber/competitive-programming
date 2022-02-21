def main():
    n, k = list(map(int, input().split()))
    string = input()

    temp_dict = {}
    counter = 0
    for i in range(n):
        if string[i] == string[i - 1]:
            counter += 1
        else:
            counter = 1

        if counter >= k:
            if string[i] in temp_dict:
                temp_dict[string[i]] += 1
            else:
                temp_dict[string[i]] = 1
            counter = 0
    print(0 if len(temp_dict) == 0 else max(temp_dict.values()))


if __name__ == "__main__":
    main()

# correct
