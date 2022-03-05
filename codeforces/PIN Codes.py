def main():
    for _ in range(int(input())):
        n = int(input())
        arr = [input() for _ in range(n)]

        counter = 0
        for i in range(n):
            element = arr[i]
            if arr.count(element) > 1:
                digit = 0
                for j in range(i + 1, n):
                    if arr[j] == element:
                        new_element = element[:3] + str(digit)
                        while new_element in arr:
                            digit += 1
                            new_element = new_element[:3] + str(digit)
                        arr[j] = new_element
                        counter += 1

        print(counter)
        for element in arr:
            print(element)


if __name__ == "__main__":
    main()

# correct
