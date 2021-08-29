for _ in range(int(input())):
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    arr.sort(key=lambda x: abs(x), reverse=True)

    counter = 0
    s = 0
    for element in arr:
        if element < 0:
            if counter < k:
                counter += 1
                s += abs(element)
            else:
                continue
        else:
            s += element
    print(s)

# correct
