def main():
    num, _, pointer = list(input().split())

    if pointer == "month":
        if int(num) <= 29:
            print(12)
        elif int(num) == 30:
            print(11)
        else:
            print(7)
    else:
        if int(num) == 5 or int(num) == 6:
            print(53)
        else:
            print(52)


if __name__ == "__main__":
    main()

# correct
