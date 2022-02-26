def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        temp_dict = {}
        for i in range(n):
            if arr[i] in temp_dict:
                temp_dict[arr[i]].append(i)
            else:
                temp_dict[arr[i]] = [i]

        mn = None
        for value in temp_dict.values():
            if len(value) == 1:
                continue
            else:
                for i in range(len(value) - 1):
                    if mn == None or mn > value[i + 1] - value[i] + 1:
                        mn = value[i + 1] - value[i] + 1

        if mn:
            print(mn)
        else:
            print(-1)


if __name__ == "__main__":
    main()

# correct
