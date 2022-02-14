def main():
    n, m = list(map(int, input().split()))
    color_flag = False
    for _ in range(n):
        temp_list = input().split()
        if "C" in temp_list or "M" in temp_list or "Y" in temp_list:
            color_flag = True

    if color_flag:
        print("#Color")
    else:
        print("#Black&White")


if __name__ == "__main__":
    main()

# correct
