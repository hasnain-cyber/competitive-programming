import sys

sys.setrecursionlimit(10**6)


def solve(counter, index, n, arr, free_for_contest, free_for_gym):
    if index == n:
        return counter

    if arr[index] == 0:
        return solve(counter + 1, index + 1, n, arr, True, True)
    elif arr[index] == 1:
        if free_for_contest:
            return solve(counter, index + 1, n, arr, False, True)
        else:
            return solve(counter + 1, index + 1, n, arr, True, True)
    elif arr[index] == 2:
        if free_for_gym:
            return solve(counter, index + 1, n, arr, True, False)
        else:
            return solve(counter + 1, index + 1, n, arr, True, True)
    else:
        if free_for_contest and not free_for_gym:
            return solve(counter, index + 1, n, arr, False, True)
        elif free_for_gym and not free_for_contest:
            return solve(counter, index + 1, n, arr, True, False)
        else:
            return min(
                solve(counter, index + 1, n, arr, False, True),
                solve(counter, index + 1, n, arr, True, False),
            )


def main():
    n = int(input())
    arr = list(map(int, input().split()))

    print(solve(0, 0, n, arr, True, True))


if __name__ == "__main__":
    main()

# tle
