n, k = list(map(int, input().split()))
arr = list(map(int, input().split()))

page = 1
counter = 0
for nProblems in arr:
    lowerBound, upperBound = 1, min(nProblems, k)
    while lowerBound <= nProblems:
        if lowerBound <= page <= min(nProblems, upperBound):
            counter += 1
        page += 1
        lowerBound += k
        upperBound += k
print(counter)

# correct
