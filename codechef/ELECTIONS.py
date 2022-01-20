def main():
    for _ in range(int(input())):
        a, b, c = list(map(int, input().split()))
        if a > 50:
            print("A")
        elif b > 50:
            print("B")
        elif c > 50:
            print("C")
        else:
            print("NOTA")


if __name__ == "__main__":
    main()

# correct
