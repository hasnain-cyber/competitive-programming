from collections import Counter

l1 = int(input())
set1 = Counter(map(int, input().split()))
l2 = int(input())
set2 = Counter(map(int, input().split()))

print(*sorted(list((set2 - (set1 & set2)).keys())))

# correct
