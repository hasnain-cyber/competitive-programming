def main():
    n = int(input())

    fibonacci_series = [0, 1]
    while fibonacci_series[-1] <= n:
        fibonacci_series.append(fibonacci_series[-1] + fibonacci_series[-2])

    for i in range(len(fibonacci_series)):
        for j in range(i + 1):
            if fibonacci_series[i] + fibonacci_series[j] == n:
                print(0, fibonacci_series[j], fibonacci_series[i])
                return
    print("I'm too stupid to solve this problem")


if __name__ == "__main__":
    main()

# correct

# lol, i could have just printed (0, 0, n) !
