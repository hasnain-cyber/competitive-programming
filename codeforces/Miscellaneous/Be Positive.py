def main():
    n = int(input())
    arr = list(map(int, input().split()))

    eligible_positive_counter, eligible_negative_counter = 0, 0
    for element in arr:
        if element > 0:
            eligible_positive_counter += 1
        elif element < 0:
            eligible_negative_counter += 1

    if eligible_positive_counter >= (n + 1) // 2:
        print(1)
    elif eligible_negative_counter >= (n + 1) // 2:
        print(-1)
    else:
        print(0)


if __name__ == "__main__":
    main()

# correct
