def main():
    for _ in range(int(input())):
        n, c = input().split()
        n = int(n)
        string = input()

        flag = True
        for i in range(n):
            if string[i] != c:
                flag = False
                break
        if flag:
            print(0)
        elif string[-1] == c:
            print(1)
            print(n)
        else:
            required_indices = []
            for i in range(n):
                if string[i] != c:
                    required_indices.append(i + 1)

            current_divisor = n - 1
            super_flag = False
            while current_divisor > 0:
                if string[current_divisor - 1] != c:
                    current_divisor -= 1
                    continue
                else:
                    flag = True
                    for index in required_indices:
                        if index % current_divisor == 0:
                            flag = False
                            break
                    if flag:
                        super_flag = True
                        break
                    else:
                        current_divisor -= 1

            if super_flag:
                print(1)
                print(current_divisor)
            else:
                print(2)
                print(n - 1, n)


if __name__ == "__main__":
    main()

# correct
