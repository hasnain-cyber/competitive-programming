def circularArrayRotation(arr, k, queries):
    length = len(arr)
    newArr = [None for _ in range(length)]
    for i in range(length):
        newArr[(i + k) % length] = arr[i]
    return [newArr[query] for query in queries]

# correct
