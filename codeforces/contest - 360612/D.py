import math


def ToCheckPowerofX(n, x):
    return_list = []
    counter = 0
    while n > 0:
        rem = n % x
        if rem == 1:
            return_list.append(counter)
        elif n % x >= 2:
            return []
        n = n // x
        counter += 1

    return return_list


def main():
    for _ in range(int(input())):
        n, k = list(map(int, input().split()))
        arr = list(map(int, input().split()))

        temp_arr = []
        for element in arr:
            if element == 0:
                continue
            else:
                temp = ToCheckPowerofX(element, k)
                if len(temp) > 0:
                    temp_arr.extend(temp)
                else:
                    print("NO")
                    return

        if len(set(temp_arr)) == len(temp_arr):
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    main()

# could not solve
