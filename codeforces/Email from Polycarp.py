def main():
    for _ in range(int(input())):
        string1, string2 = input(), input()

        arr1, arr2 = [], []
        pointer1, pointer2 = 0, 0
        while pointer1 < len(string1):
            current_char = string1[pointer1]
            count = 0
            while current_char == string1[pointer1]:
                count += 1
                pointer1 += 1
                if pointer1 == len(string1):
                    break
            arr1.append((current_char, count))

        while pointer2 < len(string2):
            current_char = string2[pointer2]
            count = 0
            while current_char == string2[pointer2]:
                count += 1
                pointer2 += 1
                if pointer2 == len(string2):
                    break
            arr2.append((current_char, count))

        if len(arr1) != len(arr2):
            print("NO")
        else:
            flag = True
            for i in range(len(arr1)):
                if not (arr1[i][0] == arr2[i][0] and arr1[i][1] <= arr2[i][1]):
                    flag = False
                    break

            print("YES" if flag else "NO")


if __name__ == "__main__":
    main()

# correct
