def main():
    n, b, d = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    s, counter = 0, 0
    for element in arr:
        if element <= b:
            s += element
        if s > d:
            counter += 1
            s = 0
    print(counter)


if __name__ == "__main__":
    main()

# correct
