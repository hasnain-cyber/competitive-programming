n = int(input())
arr = list(map(int, input().split()))
freqArr = [0 for i in range(100)]

for i in range(n):
    freqArr[arr[i]] += 1
for i in range(len(freqArr)):
    for _ in range(freqArr[i]):
        print(i, end=' ')

# correct
