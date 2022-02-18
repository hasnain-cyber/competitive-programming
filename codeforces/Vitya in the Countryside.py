def main():
    n = int(input())
    arr = list(map(int, input().split()))

    if n == 1:
        if arr[0] == 0:
            print("UP")
        elif arr[0] == 15:
            print("DOWN")
        else:
            print(-1)
    else:
        if arr[-1] > arr[-2]:
            if arr[-1] == 15:
                print("DOWN")
            else:
                print("UP")
        else:
            if arr[-1] == 0:
                print("UP")
            else:
                print("DOWN")


if __name__ == "__main__":
    main()

# correct
