def main():
    for _ in range(int(input())):
        n = int(input())

        counter = 0
        while n > 1:
            if n % 2 != 1:
                counter += 1
            n = n // 2
        print(counter)


if __name__ == "__main__":
    main()

# correct
