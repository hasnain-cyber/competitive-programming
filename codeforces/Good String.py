from collections import Counter


def main():
    for _ in range(int(input())):
        string = input()

        counter_dict = Counter(string)

        max_length = float("-inf")
        for key in counter_dict:
            max_length = max(max_length, counter_dict[key])

        counter_counter_dict = Counter(counter_dict.values())
        for key in counter_counter_dict:
            if counter_counter_dict[key] >= 2:
                max_length = max(max_length, key * 2)

        print(len(string) - max_length)


if __name__ == "__main__":
    main()

# wrong answer
