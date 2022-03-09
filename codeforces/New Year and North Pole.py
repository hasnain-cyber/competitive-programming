def main():
    c = 20000

    y = c / 2

    flag = True
    for _ in range(int(input())):
        distance, direction = input().split()
        distance = int(distance)

        new_y = y
        if direction == "North":
            new_y += distance
        elif direction == "South":
            new_y -= distance
        else:
            if y in (c / 2, -c / 2):
                flag = False

        if not -c / 2 <= new_y <= c / 2:
            flag = False
        else:
            y = new_y

    if not y == c / 2:
        flag = False

    print("YES" if flag else "NO")


if __name__ == "__main__":
    main()

# correct
