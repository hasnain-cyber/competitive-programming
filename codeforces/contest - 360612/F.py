def main():
    n, b, a = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    a_current = a
    for index, segment in enumerate(arr):
        if segment == 1:
            if a_current == a or b == 0:
                a_current -= 1
            else:
                b -= 1
                a_current = min(a_current + 1, a)
        else:
            if a_current > 0:
                a_current -= 1
            else:
                b -= 1
        if a_current == 0 and b == 0:
            print(index + 1)
            return
    print(n)


if __name__ == "__main__":
    main()

# correct
