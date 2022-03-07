def main():
    n = int(input())
    string = input()

    counter1 = 0
    character1 = string[0]
    for i in range(n):
        if string[i] == character1:
            counter1 += 1
        else:
            break

    counter2 = 0
    character2 = string[-1]
    for i in range(n - 1, -1, -1):
        if string[i] == character2:
            counter2 += 1
        else:
            break

    if counter1 == n or counter2 == n:
        answer = n * (n + 1) // 2
    else:
        if character1 == character2:
            answer = (counter1 + 1) * (counter2 + 1)
        else:
            answer = counter1 + counter2 + 1

    print(answer % 998244353)


if __name__ == "__main__":
    main()

# correct
