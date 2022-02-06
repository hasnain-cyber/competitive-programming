def main():
    for _ in range(int(input())):
        n, k = list(map(int, input().split()))
        s = input()
        s_reversed = "".join(reversed(s))

        if k == 0:
            print(1)
        else:
            if s == s_reversed:
                print(1)
            else:
                print(2)


if __name__ == "__main__":
    main()

# correct
