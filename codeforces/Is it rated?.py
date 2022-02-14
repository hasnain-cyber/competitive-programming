def main():
    arr_before, arr_after = [], []
    n = int(input())
    for _ in range(n):
        temp_input = list(map(int, input().split()))
        arr_before.append(temp_input[0])
        arr_after.append(temp_input[1])

    for i in range(n):
        if arr_before[i] != arr_after[i]:
            print("rated")
            return

    for i in range(n):
        for j in range(i):
            if arr_before[i] > arr_before[j]:
                print("unrated")
                return

    print("maybe")


if __name__ == "__main__":
    main()

# correct
