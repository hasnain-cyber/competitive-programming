for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))

    setA, setB = set(), set()
    for index, value in enumerate(arr):
        if index % 2 == 0:
            setA.add(value)
        else:
            setB.add(value)

    setArr = set(arr)
    if setArr.__eq__(setA):
        print(*sorted(setA))
    if setArr.__eq__(setB):
        print(*sorted(setB))
    else:
        print(-1)

# wrong
