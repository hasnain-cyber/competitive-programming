def main():
    for _ in range(int(input())):
        a, b, c = input(), input(), input()

        flag = True
        for i in range(len(a)):
            if (a[i] == b[i] and b[i] != c[i]) or (
                a[i] != b[i] and b[i] != c[i] and c[i] != a[i]
            ):
                flag = False
                break
        if flag:
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    main()

# correct
