def main():
    string = input()
    length = len(string)

    a, b = [], []
    for i in range(length):
        if string[i] == "(":
            a.append(i)
        else:
            b.append(i)

    removed_indices = []
    if len(a) > 0 and len(b) > 0:
        while not a[0] > b[-1]:
            removed_indices.append(a.pop(0) + 1)
            removed_indices.append(b.pop() + 1)

            if len(a) == 0 or len(b) == 0:
                break

    if len(removed_indices) == 0:
        print(0)
    else:
        print(1)
        print(len(removed_indices))
        print(*sorted(removed_indices))


if __name__ == "__main__":
    main()

# correct
