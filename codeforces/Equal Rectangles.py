def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        arr.sort()

        temp_dict = {}
        for element in arr:
            if element in temp_dict:
                temp_dict[element] += 1
            else:
                temp_dict[element] = 1

        flag = True
        for value in temp_dict.values():
            if value % 2 != 0:
                flag = False
                break
        if not flag:
            print("No")
            continue

        area = arr[0] * arr[-1]
        flag = True
        for i in range(0, 2 * n, 2):
            temp_area = arr[i] * arr[4 * n - i - 1]
            if temp_area != area:
                flag = False
                break

        print("Yes" if flag else "No")


if __name__ == "__main__":
    main()

# correct
