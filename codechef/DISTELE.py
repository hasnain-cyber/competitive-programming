for _ in range(int(input())):
    length = int(input())
    arr = list(map(int, input().split()))

    temp_dict = dict()
    for element in arr:
        if element in temp_dict:
            temp_dict[element] += 1
        else:
            temp_dict[element] = 1

    total = 1
    for key in temp_dict.keys():
        total *= temp_dict[key] + 1
    print((total - 1) % (10 ** 9 + 7))

# correct
