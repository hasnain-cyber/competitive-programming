import math

for _ in range(int(input())):
    lowerBound, upperBound = list(map(int, input().split()))

    counter = 0
    currentNumber = int(math.ceil(math.sqrt(lowerBound)))
    while currentNumber ** 2 <= upperBound:
        currentNumber += 1
        counter += 1
    print(counter)

# correct
