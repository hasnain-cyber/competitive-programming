def main():
    temp_arr = list(map(int, input().split()))
    temp_arr.sort()
    a, b, c = temp_arr
    answer = min((a + b + c) // 3, b + c)
    print(answer)


if __name__ == "__main__":
    main()

# could not solve
