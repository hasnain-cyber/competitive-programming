import math

for _ in range(int(input())):
    n, k = tuple(map(int, input().split()))
    t = math.floor(math.log(k, 2)) + 1

    totalPatches = 2 ** t
    if totalPatches > n:
        timeSpent = math.ceil(math.log(n, 2))
    else:
        timeSpent = t
        remainingPatches = n - totalPatches
        timeSpent += math.ceil(remainingPatches / k)
    print(timeSpent)

# wrong answer - test case 6
