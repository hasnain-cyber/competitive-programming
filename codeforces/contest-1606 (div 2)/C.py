def check(value, denominations, k):
    totalNotes = 0
    for denomination in reversed(denominations):
        notesRequired = value // denomination
        value -= notesRequired * denomination
        totalNotes += notesRequired
    return value == 0 and totalNotes <= k


for _ in range(int(input())):
    n, k = tuple(map(int, input().split()))
    denominations = list(map(lambda x: 10 ** int(x), input().split()))

    i = 1
    while True:
        if not check(i, denominations, k):
            print(i)
            break
        i += 1
