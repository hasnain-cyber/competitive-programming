from math import factorial


def main():
    actual_commands = input()
    received_commands = input()
    length = len(actual_commands)

    actual_position, received_position, counter = 0, 0, 0
    for i in range(length):
        if actual_commands[i] == "+":
            actual_position += 1
        elif actual_commands[i] == "-":
            actual_position -= 1

        if received_commands[i] == "+":
            received_position += 1
        elif received_commands[i] == "-":
            received_position -= 1
        else:
            counter += 1

    if counter == 0:
        if actual_position == received_position:
            print(1)
        else:
            print(0)
    else:
        difference = abs(actual_position - received_position)
        if difference > counter:
            print(0)
        else:
            if (counter - difference) % 2 == 0:
                v1 = (counter - difference) // 2
                v2 = difference + v1
                print(
                    (1 / 2) ** counter
                    * (factorial(v1 + v2) // (factorial(v1) * factorial(v2)))
                )
            else:
                print(0)


if __name__ == "__main__":
    main()

# correct
