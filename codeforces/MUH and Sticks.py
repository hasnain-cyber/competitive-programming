def main():
    arr = list(map(int, input().split()))

    required_element = -1
    for element in arr:
        if arr.count(element) >= 4:
            required_element = element
            break

    if required_element == -1:
        print("Alien")
        return

    counter = 4
    remaining_sticks = []
    for element in arr:
        if element == required_element:
            if counter > 0:
                counter -= 1
                continue
            else:
                remaining_sticks.append(element)
        else:
            remaining_sticks.append(element)

    if remaining_sticks[0] == remaining_sticks[1]:
        print("Elephant")
    else:
        print("Bear")


if __name__ == "__main__":
    main()

# correct
