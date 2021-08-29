for _ in range(int(input())):
    n = int(input())
    weightList = list(map(int, input().split()))

    counter = 0
    for i in range(n - 1):
        j = i + 1
        if not j - i == weightList[j] - weightList[i]:
            counter += 1
    if counter > 0:
        print(1)
    else:
        print(n)

# correct
