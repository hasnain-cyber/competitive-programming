def main():
    n, b = map(int, input().split())
    arr = list(map(int, input().split()))

    even_counter, odd_counter = 0, 0
    temp_list = []
    for i in range(n - 1):
        if arr[i] % 2 == 0:
            even_counter += 1
        else:
            odd_counter += 1

        if even_counter == odd_counter and even_counter != 0:
            temp_list.append((i, abs(arr[i] - arr[i + 1])))

    temp_list.sort(key=lambda x: x[1])
    counter = 0
    s = 0
    for element in temp_list:
        s += element[1]
        if s > b:
            break
        else:
            counter += 1
    print(counter)


if __name__ == "__main__":
    main()

# correct
