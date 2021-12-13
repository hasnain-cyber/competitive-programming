def commonSubjects(mem1, mem2):
    subCounter = 0
    for i in range(length):
        if mem1[i] == '1' or mem2[i] == '1':
            subCounter += 1
    return subCounter


teams = []
maxSubjects = 0
maxCounter = 0

nTestCases, length = list(map(int, input().split()))
for _ in range(nTestCases):
    newTeam = input()
    for team in teams:
        newCommonSubjects = commonSubjects(team, newTeam)
        if newCommonSubjects > maxSubjects:
            maxSubjects = newCommonSubjects
            maxCounter = 1
        elif newCommonSubjects == maxSubjects:
            maxCounter += 1
    teams.append(newTeam)

print(maxSubjects)
print(maxCounter)

# correct
