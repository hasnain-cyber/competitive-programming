def main():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()

    current_element = 1
    counter = 0
    for element in arr:
        counter += abs(element - current_element)
        current_element += 1

    print(counter)


if __name__ == "__main__":
    main()

# correct
