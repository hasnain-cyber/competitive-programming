def count_inversions(arr):
    count = 0
    for i in range(len(arr) - 1):
        for j in range(i + 1, len(arr)):
            if arr[i] > arr[j]:
                count += 1
    return count


def main():
    for _ in range(int(input())):
        length = int(input())
        arr = list(map(int, input().split()))

        nInversions = count_inversions(arr)

        if nInversions % 2 == 0:
            print('YES')
        else:
            print('NO')


main()

# correct
