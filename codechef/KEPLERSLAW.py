def main():
    for _ in range(int(input())):
        t1, t2, a1, a2 = list(map(int, input().split()))

        if (t1 / t2) ** 2 == (a1 / a2) ** 3:
            print("Yes")
        else:
            print("No")


if __name__ == "__main__":
    main()

# correct