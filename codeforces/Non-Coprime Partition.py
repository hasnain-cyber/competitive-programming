def main():
    n = int(input())

    if n <= 2:
        print("No")
    else:
        print("Yes")
        k = n // 2 if n % 2 == 0 else (n + 1) // 2
        print(1, k)
        temp_arr = [i for i in range(1, n + 1) if i != k]
        print(n - 1, *temp_arr)


if __name__ == "__main__":
    main()

# correct
