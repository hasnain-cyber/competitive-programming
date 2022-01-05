def main():
    n = int(input())
    a = list(map(int, input().split()))
    nOne = a.count(1)
    answer, current_score = 0, 0
    for i in range(n):
        if a[i] == 0:
            current_score += 1
        else:
            if current_score > 0:
                current_score -= 1
        answer = max(answer, current_score)
    print(answer + nOne)


if __name__ == "__main__":
    main()

# correct
