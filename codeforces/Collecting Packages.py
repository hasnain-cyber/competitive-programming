def main():
    for _ in range(int(input())):
        n = int(input())
        arr = [tuple(map(int, input().split())) for _ in range(n)]
        arr.sort()

        current_position = (0, 0)
        ans_string = ""
        flag = True
        for package_position in arr:
            x_difference, y_difference = (
                package_position[0] - current_position[0],
                package_position[1] - current_position[1],
            )

            if y_difference < 0:
                flag = False
                break

            ans_string += "R" * x_difference + "U" * y_difference
            current_position = (
                current_position[0] + x_difference,
                current_position[1] + y_difference,
            )

        if flag:
            print("YES")
            print(ans_string)
        else:
            print("NO")


if __name__ == "__main__":
    main()

# correct
