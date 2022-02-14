def main():
    n = int(input())
    string = [character for character in input()]

    counter = 0
    for i in range(0, n, 2):
        if string[i : i + 2] == ["a", "a"]:
            string[i] = "b"
            counter += 1
        elif string[i : i + 2] == ["b", "b"]:
            string[i] = "a"
            counter += 1
    print(counter)
    print("".join(string))


if __name__ == "__main__":
    main()

# correct
