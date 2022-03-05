def main():
    n = int(input())
    arr = list(map(int, input().split()))

    one_indices = [i for i, x in enumerate(arr) if x == 1]

    if len(one_indices) == 0:
        print(0)
    else:
        counter = 1
        for i in range(len(one_indices) - 1):
            counter *= one_indices[i + 1] - one_indices[i]
        print(counter)


if __name__ == "__main__":
    main()

# correct
