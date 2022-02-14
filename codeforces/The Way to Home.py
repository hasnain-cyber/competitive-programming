def main():
    n, d = list(map(int, input().split()))
    string = input()

    current_pos = 0
    counter = 0
    while True:
        decided_pos = -1
        for i in range(current_pos + 1, min(n, current_pos + d + 1)):
            if string[i] == "1":
                decided_pos = i

        if decided_pos == -1:
            print(-1)
            return
        else:
            current_pos = decided_pos
            counter += 1

        if current_pos == n - 1:
            print(counter)
            return


if __name__ == "__main__":
    main()

# correct
