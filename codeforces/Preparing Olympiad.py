from itertools import combinations


def main():
    n, l, r, x = map(int, input().split())
    arr = list(map(int, input().split()))

    counter = 0
    for i in range(2, n + 1):
        question_combinations = combinations(arr, i)
        for question_combination in question_combinations:
            mn, mx = min(question_combination), max(question_combination)
            if l <= sum(question_combination) <= r and mx - mn >= x:
                counter += 1
    print(counter)


if __name__ == "__main__":
    main()

# correct
