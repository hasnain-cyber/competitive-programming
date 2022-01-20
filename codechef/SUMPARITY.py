def main():
    for _ in range(int(input())):
        n, a = list(map(int, input().split()))

        if n % 2 == 1 and a % 2 == 0:
            print("impossible")
        else:
            if a % 2 == 0:
                print("even")
            else:
                print("odd")


if __name__ == "__main__":
    main()

# could not solve
