def main():
    n = int(input())
    arr = list(map(int, input().split()))
    temp_dict = dict()
    for element in arr:
        if element in temp_dict:
            temp_dict[element] += 1
        else:
            temp_dict[element] = 1

    if not 0 in temp_dict:
        print(-1)
        return
    else:
        if 5 in temp_dict:
            use5 = (temp_dict[5] // 9) * 9
            if use5 == 0:
                print(0)
            else:
                print("5" * use5 + "0" * temp_dict[0])
        else:
            print(0)


if __name__ == "__main__":
    main()

# correct
