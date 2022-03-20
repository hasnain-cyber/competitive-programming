from string import ascii_lowercase


def main():
    for _ in range(int(input())):
        n = int(input())
        string = input()

        index = -1
        for character in ascii_lowercase:
            temp_index = string.find(character)
            if temp_index != -1:
                index = temp_index
                break

        k = index + 1
        answer_string = string
        for i in range(0, n - k + 1):
            answer_string = (
                answer_string[:i]
                + "".join(reversed(answer_string[i : i + k]))
                + answer_string[i + k :]
            )

        print(answer_string)
        print(k)


if __name__ == "__main__":
    main()

# could not solve
