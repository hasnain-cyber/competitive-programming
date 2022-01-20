def main():
    for _ in range(int(input())):
        k = int(input())

        current_divisor = 2
        counter = 0
        while k % current_divisor == 0:
            current_divisor *= 2
            counter += 1
        print(counter)


if __name__ == "__main__":
    main()

# correct
