import mpmath

n = 10
minValue = -20
maxValue = 20
onlyIntegers = True

arr = []
while len(arr) < n:
    randomFactor = mpmath.rand()
    randomNumber = randomFactor * maxValue + (randomFactor - 1) * abs(minValue)

    if onlyIntegers:
        randomNumber = int(randomNumber)

    arr.append(randomNumber)

print(*arr)
