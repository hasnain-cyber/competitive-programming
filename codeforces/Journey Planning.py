def main():
    n = int(input())
    arr = list(map(int, input().split()))

    temp_dict = {}
    for i in range(n):
        k = arr[i] - i
        if k in temp_dict:
            temp_dict[k] += arr[i]
        else:
            temp_dict[k] = arr[i]

    print(max(temp_dict.values()))


if __name__ == "__main__":
    main()

# correct
