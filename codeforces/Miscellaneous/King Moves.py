def main():
    temp_string = input()
    p1, p2 = temp_string[0], temp_string[1]

    flag1, flag2 = p1 in ("a", "h"), p2 in ("1", "8")
    if flag1 and flag2:
        print(3)
    elif (flag1, flag2) in [(True, False), (False, True)]:
        print(5)
    else:
        print(8)


if __name__ == "__main__":
    main()

# correct
