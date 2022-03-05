def main():
    n = int(input())
    arr = list(map(int, input().split()))
    sorted_arr = sorted(arr)

    counter = 0
    for i in range(n):
        if arr[i] != sorted_arr[i]:
            counter += 1

    if counter <= 2:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()

# correct
