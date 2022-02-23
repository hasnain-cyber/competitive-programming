def main():
    n, a, b = list(map(int, input().split()))
    string = input()

    if n == 1:
        print(0)
    else:
        if string[a - 1] == string[b - 1]:
            print(0)
        else:
            print(1)


if __name__ == "__main__":
    main()

# correct
