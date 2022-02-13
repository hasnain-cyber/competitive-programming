def main():
    n = int(input())
    arr = list(map(int, input().split()))

    s = 0
    pointer = 0
    while s < n:
        if pointer == 7:
            pointer = 0
        s += arr[pointer]
        pointer += 1
    print(pointer)


if __name__ == "__main__":
    main()

# correct
