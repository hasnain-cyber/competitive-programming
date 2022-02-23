def main():
    n = int(input())
    arr = list(map(int, input().split()))

    if arr == [1 for _ in range(n)]:
        # if the whole array only consists of 1 so we have to delete at least one 1 so that we can say that we have made a move.
        print(n - 1)
    else:
        answer = 0
        final_answer = 0
        for i in range(n):
            if arr[i] == 0:
                answer += 1
            else:
                answer -= 1

            answer = max(answer, 0)
            final_answer = max(final_answer, answer)

        print(sum(arr) + final_answer)


if __name__ == "__main__":
    main()

# correct
