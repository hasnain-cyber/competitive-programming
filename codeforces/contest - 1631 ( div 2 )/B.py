def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        target = arr[-1]

        action_counter = 0
        counter = 0
        stored_power = 1
        for index, element in enumerate(reversed(arr), 1):
            if element != target:
                counter += 1
            else:
                stored_power = index + 1
                if counter == 0:
                    continue
                else:
                    counter = 0
                    action_counter += 1

            if counter == stored_power:
                counter = 0
                stored_power = index + 1
                action_counter += 1

        if counter > 0:
            action_counter += 1
        print(action_counter)


if __name__ == "__main__":
    main()

# wrong answer
