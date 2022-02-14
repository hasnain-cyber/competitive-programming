def main():
    n = int(input())
    arr = list(map(int, input().split()))

    odd_arr = [number for number in arr if number % 2 == 1]
    even_arr = [number for number in arr if number % 2 == 0]

    s = sum(even_arr)
    if len(odd_arr) % 2 == 0:
        s += sum(odd_arr)
    else:
        s += sum(odd_arr) - min(odd_arr)

    print(s)


if __name__ == "__main__":
    main()

# correct
