for _ in range(int(input())):
    a, b = tuple(map(int, input().split()))
    mn, mx = min(a, b), max(a, b)
    assignedPairs = mn
    remainingPairs = (mx - mn) // 2

    if assignedPairs >= remainingPairs:
        totalTeams = remainingPairs + (assignedPairs - remainingPairs) // 2
    else:
        totalTeams = assignedPairs

    print(totalTeams)

# correct
