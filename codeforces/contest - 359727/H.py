def main():
    n, m = tuple(map(int, input().split()))
    arr = list(map(int, input().split()))

    s = 0
    answerArr = []
    for ai in arr:
        startingPoint = s - (s // m) * m
        pagesTurned = (startingPoint + ai) // m
        answerArr.append(pagesTurned)
        s += ai
    print(*answerArr)


if __name__ == '__main__':
    main()

# correct
