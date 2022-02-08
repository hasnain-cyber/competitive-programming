def main():
    n = int(input())
    arr = list(map(int, input().split()))
    s, t = list(map(int, input().split()))
    s1, t1 = min(s, t), max(s, t)

    answer = 0
    for i in range(s1 - 1, t1 - 1):
        answer += arr[i]

    alternate_answer = sum(arr) - answer
    print(min(answer, alternate_answer))


if __name__ == "__main__":
    main()

# correct
