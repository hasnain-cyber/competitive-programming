def main():
    k, n = int(input()), input()

    s = 0
    for digit in n:
        s += int(digit)

    if s >= k:
        print(0)
    else:
        count_changed = 0
        for i in range(0, 10):
            count = n.count(str(i))
            for _ in range(1, count + 1):
                s += 9 - i
                count_changed += 1
                if s >= k:
                    print(count_changed)
                    return


if __name__ == "__main__":
    main()


# correct
