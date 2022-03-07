def main():
    n, m = map(int, input().split())
    arr = [input().split() for _ in range(m)]

    answer_string = ""
    for i in range(n):
        if i % 2 == 0:
            answer_string += "1"
        else:
            answer_string += "0"

    print(answer_string)


if __name__ == "__main__":
    main()

# correct
