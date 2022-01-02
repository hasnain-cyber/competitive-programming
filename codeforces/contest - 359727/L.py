def main():
    for _ in range(int(input())):
        s = input()

        current_char = s[0]
        counter = 0
        answerSet = set()
        for character in s:
            if current_char == character:
                counter += 1
            else:
                if counter % 2 != 0:
                    answerSet.add(current_char)
                current_char = character
                counter = 1
        if counter % 2 != 0:
            answerSet.add(current_char)
        print(''.join(list(sorted(answerSet))))


if __name__ == '__main__':
    main()

# correct
