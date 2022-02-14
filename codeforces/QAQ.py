def main():
    string = input()

    q_indices = []
    a_indices = []
    for index, value in enumerate(string):
        if value == "Q":
            q_indices.append(index)
        elif value == "A":
            a_indices.append(index)

    total_counter = 0
    for a_index in a_indices:
        counter = 0
        for q_index in q_indices:
            if a_index > q_index:
                counter += 1
            else:
                break
        total_counter += counter * (len(q_indices) - counter)
    print(total_counter)


if __name__ == "__main__":
    main()

# correct
