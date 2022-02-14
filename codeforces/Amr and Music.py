def main():
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    for index, value in enumerate(arr):
        arr[index] = (index, value)
    arr.sort(key=lambda x: x[1])

    learn_arr = []
    s = 0
    for element in arr:
        s += element[1]
        if s > k:
            break
        else:
            learn_arr.append(element[0] + 1)

    print(len(learn_arr))
    print(*learn_arr)


if __name__ == "__main__":
    main()

# correct
