def main():
    counter = 0
    for _ in range(int(input())):
        temp_tuple = tuple(map(int, input().split()))
        if temp_tuple.count(1) >= 2:
            counter += 1
    print(counter)


if __name__ == "__main__":
    main()

# correct
