def main():
    n = int(input())
    arr = list(map(int, input().split()))

    temp_dict = {}
    for element in arr:
        if element in temp_dict:
            temp_dict[element] += 1
        else:
            temp_dict[element] = 1

    print(n - max(temp_dict.values()))


if __name__ == "__main__":
    main()

# correct
