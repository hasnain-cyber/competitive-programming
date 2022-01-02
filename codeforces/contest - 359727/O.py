def main():
    for _ in range(int(input())):
        A, B = list(map(int, input().split()))

        counter = 0
        for a in range(1, A + 1):
            for b in range(1, B + 1):
                if a * b + a + b == int(f'{a}{b}'):
                    counter += 1
        print(counter)


if __name__ == "__main__":
    main()

# tle
