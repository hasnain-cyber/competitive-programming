def main():
    copies, originals = map(int, input().split())

    c1 = originals - 1
    if c1 == 0:
        if copies > 0:
            print("No")
        else:
            c2 = (copies - originals + 1) / 2
            if c2 >= 0 and c2.is_integer():
                print("Yes")
            else:
                print("No")
    elif c1 < 0:
        print("No")
    else:
        c2 = (copies - originals + 1) / 2
        if c2 >= 0 and c2.is_integer():
            print("Yes")
        else:
            print("No")


if __name__ == "__main__":
    main()

# correct
