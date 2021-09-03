length = int(input())
arr = list(map(int, input().split()))

pivot = arr[0]
left = []
right = []
equal = []
for element in arr:
    if pivot == element:
        equal.append(element)
    elif pivot > element:
        left.append(element)
    else:
        right.append(element)
print(*(left + equal + right))

# correct
