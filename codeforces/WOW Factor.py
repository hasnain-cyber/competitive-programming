def main():
    string = input()

    counter_w, counter_wo, counter_wow = 0, 0, 0
    for i in range(len(string)):
        if string[i] == "o":
            counter_wo += counter_w
        elif string[i] == "v" and string[i - 1] == "v" and i > 0:
            counter_w += 1
            counter_wow += counter_wo

    print(counter_wow)


if __name__ == "__main__":
    main()

# correct
