def main():
    n = int(input())
    current_combo = input()
    correct_combo = input()

    counter = 0
    for i in range(n):
        difference = abs(int(current_combo[i]) - int(correct_combo[i]))
        counter += min(difference, 10 - difference)
    print(counter)


if __name__ == "__main__":
    main()

# correct
