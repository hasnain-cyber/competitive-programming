def main():
    n = int(input())
    arr = list(map(int, input().split()))

    temp_dict = dict()
    for element in arr:
        if element in temp_dict:
            temp_dict[element] += 1
        else:
            temp_dict[element] = 1
        if temp_dict[element] > 2 and element != 0:
            print(-1)
            return

    counter = 0
    for key in temp_dict:
        if temp_dict[key] == 2 and key != 0:
            counter += 1
    print(counter)


if __name__ == "__main__":
    main()

# correct
