def main():
    n, k = list(map(int, input().split()))
    string = "".join(sorted(input()))

    answer_string = ""
    previous_ord = -1
    for i in range(n):
        if previous_ord == -1:
            answer_string += string[i]
            previous_ord = ord(string[i])
        else:
            if ord(string[i]) - previous_ord > 1:
                answer_string += string[i]
                previous_ord = ord(string[i])

        if len(answer_string) == k:
            s = 0
            for character in answer_string:
                s += ord(character) - ord("a") + 1
            print(s)
            return

    print(-1)


if __name__ == "__main__":
    main()

# correct
