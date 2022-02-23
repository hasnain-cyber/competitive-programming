def main():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()

    current_target = 1
    for i in range(n):
        if arr[i] == current_target:
            current_target += 1
        elif arr[i] > current_target:
            arr[i] = current_target
            current_target += 1
    print(current_target)


if __name__ == "__main__":
    main()

# correct
