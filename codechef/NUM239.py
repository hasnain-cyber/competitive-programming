def main():
    for _ in range(int(input())):
        a, b = list(map(int, input().split()))

        counter = 0
        for i in range(a, b + 1):
            if i % 10 in [2, 3, 9]:
                counter += 1
        print(counter)


if __name__ == "__main__":
    main()

# correct
