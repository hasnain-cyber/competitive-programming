def main():
    for _ in range(int(input())):
        string = input()
        n = len(string)

        temp_indices = []
        for i in range(n):
            if string[i] in (string[0], string[-1]):
                temp_indices.append(i)

        mx = float("-inf")
        for i in range(len(temp_indices) - 1):
            if temp_indices[i + 1] - temp_indices[i] - 1 > 0:
                mx = max(mx, temp_indices[i + 1] - temp_indices[i] - 1)

        print(mx if mx != float("-inf") else -1)


if __name__ == "__main__":
    main()

# correct
