def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        arr.sort()
        permutation_arr = [i for i in range(1, n + 1)]

        wrong_index = -1
        for i in range(n):
            if arr[i] != permutation_arr[i]:
                wrong_index = i
                break

        if wrong_index == -1:
            print("YES", n + 1)
        else:
            x = arr[wrong_index] - (wrong_index + 1)
            for i in range(wrong_index, n):
                arr[i] %= x

            print(f"YES {x}" if arr == permutation_arr else "NO")


if __name__ == "__main__":
    main()

# could not solve
