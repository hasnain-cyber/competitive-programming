def main():
    n = int(input())
    arr1 = sorted(map(int, input().split()))
    arr2 = sorted(map(int, input().split()))
    arr3 = sorted(map(int, input().split()))

    flag = False
    for i in range(len(arr2)):
        if arr1[i] != arr2[i]:
            print(arr1[i])
            flag = True
            break
    if not flag:
        print(arr1[-1])

    flag = False
    for i in range(len(arr3)):
        if arr2[i] != arr3[i]:
            print(arr2[i])
            flag = True
            break
    if not flag:
        print(arr2[-1])


if __name__ == "__main__":
    main()

# correct
