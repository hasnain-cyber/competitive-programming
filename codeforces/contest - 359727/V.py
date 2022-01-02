def main():
    for _ in range(int(input())):
        arr = []
        for i in range(9):
            arr.append(list(input()))

        for i in range(3):
            for j in range(3):
                value = arr[3 * i + j][3 * j + i]
                if value == '9':
                    value = '1'
                else:
                    value = str(int(value) + 1)
                arr[3 * i + j][3 * j + i] = value

        for s in arr:
            print(''.join(s))


if __name__ == "__main__":
    main()
