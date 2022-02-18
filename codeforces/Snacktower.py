def main():
    n = int(input())
    arr = list(map(int, input().split()))

    current_pointer = n
    current_arr = []
    reserve_set = set()
    for element in arr:
        if element == current_pointer:
            temp_arr = [element]
            current_pointer -= 1
            while current_pointer != 0:
                if current_pointer in reserve_set:
                    temp_arr.append(current_pointer)
                    current_pointer -= 1
                else:
                    break
            current_arr.append(temp_arr)
        else:
            reserve_set.add(element)
            current_arr.append([])

    for floor in current_arr:
        print(*floor)


if __name__ == "__main__":
    main()

# correct
