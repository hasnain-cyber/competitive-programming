edges = set()
nodeDict = {}

nNodes, nEdges = list(map(int, input().split()))
for _ in range(nEdges):
    edge = tuple(map(int, input().split()))
    if edge[0] in nodeDict.keys():
        nodeDict[edge[0]].append(edge[1])
    else:
        nodeDict[edge[0]] = [edge[1]]
    if edge[1] in nodeDict.keys():
        nodeDict[edge[1]].append(edge[0])
    else:
        nodeDict[edge[1]] = [edge[0]]
print(nodeDict)

mainCounter = 0
counter = 1
while counter > 0:
    counter = 0
    for node in nodeDict.keys():
        if len(nodeDict[node]) % 2 == 0:
            mainCounter += 1
            counter += 1
            break
print(mainCounter)

# wrong
