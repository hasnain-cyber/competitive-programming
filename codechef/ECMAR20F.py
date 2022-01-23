def main():
    for _ in range(int(input())):
        n, c = list(map(int, input().split()))
        string = input()
        counter = 0
        counter_set = set()
        for character in string:
            if character not in counter_set:
                counter += 1
                counter_set.add(character)

        print(max(0, c - counter))


if __name__ == "__main__":
    main()

# correct
