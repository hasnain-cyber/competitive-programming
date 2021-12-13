def find_absolute_permutations(n, k):
    returnArr = [0 for _ in range(n)]
    usedSet = set()
    for i in range(1, n + 1):
        x1, x2 = i + k, i - k
        if 0 < x1 <= n and not 0 < x2 <= n:
            if x1 not in usedSet:
                returnArr[i - 1] = x1
                usedSet.add(x1)
            else:
                return [-1]
        elif 0 < x2 <= n and not 0 < x1 <= n:
            if x2 not in usedSet:
                returnArr[i - 1] = x2
                usedSet.add(x2)
            else:
                return [-1]
        elif 0 < x1 <= n and 0 < x2 <= n:
            number = min(x1, x2)
            if number in usedSet:
                number = max(x1, x2)
            if number in usedSet:
                return [-1]
            returnArr[i - 1] = number
            usedSet.add(number)
        else:
            return [-1]

    return returnArr


def main():
    for _ in range(int(input())):
        n, k = tuple(map(int, input().split()))
        print(*find_absolute_permutations(n, k))


main()

# correct
