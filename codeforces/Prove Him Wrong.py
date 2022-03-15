def main():
    for _ in range(int(input())):
        n = int(input())

        ans_arr = [1]
        while len(ans_arr) < n and ans_arr[-1] <= 10**9 / 3:
            ans_arr.append(ans_arr[-1] * 3)

        if len(ans_arr) == n:
            print("YES")
            print(*ans_arr)
        else:
            print("NO")


if __name__ == "__main__":
    main()

# correct
