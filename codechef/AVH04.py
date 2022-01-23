def main():
    n = int(input())

    score_set = dict()
    for _ in range(n * (n - 1) // 2):
        t1, t2, g1, g2 = list(map(int, input().split()))
        if g1 > g2:
            t1_score, t2_score = 4, 0
        elif g2 > g1:
            t1_score, t2_score = 0, 4
        else:
            t1_score, t2_score = 1, 1

        if t1 in score_set:
            value = score_set[t1]
            score_set[t1] = (value[0] + t1_score, value[1] + g1)
        else:
            score_set[t1] = (t1_score, g1)

        if t2 in score_set:
            value = score_set[t2]
            score_set[t2] = (value[0] + t2_score, value[1] + g2)
        else:
            score_set[t2] = (t2_score, g2)

    max_value, max_team = (-1, -1), -1
    for key, value in score_set.items():
        if (value[0] > max_value[0]) or (
            value[0] == max_value[0] and value[1] > max_value[1]
        ):
            max_value = value
            max_team = key

    print(max_team)


if __name__ == "__main__":
    main()

# correct
