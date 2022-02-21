def main():
    n = int(input())
    arr = list(map(int, input().split()))

    current_winner = 1 if arr[0] % 2 == 0 else 2
    answer_arr = [current_winner]
    for i in range(1, n):
        if arr[i] % 2 == 0:
            if current_winner == 1:
                current_winner = 2
            else:
                current_winner = 1

        answer_arr.append(current_winner)

    for element in answer_arr:
        print(element)


if __name__ == "__main__":
    main()

# correct
