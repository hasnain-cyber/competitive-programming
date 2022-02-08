from tabnanny import check


def main():
    n = int(input())
    i = 1
    while True:
        check = i * (i + 1) * (i + 2) // 6
        if not check <= n:
            break
        i += 1
    print(i - 1)


if __name__ == "__main__":
    main()

# correct
