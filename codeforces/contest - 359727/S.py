def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        answer_arr = ['' for _ in range(n + 1)]
        current_char = 'a'
        answer_arr[0] = current_char
        for i in range(len(arr)):
            current_char = chr(ord(current_char) + 1)
            if arr[i] == 0:
                answer_arr[i + 1] = current_char
            else:
                if len(answer_arr[i]) >= arr[i]:
                    answer_arr[i + 1] = answer_arr[i][:arr[i]]
                else:
                    answer_arr[i + 1] = answer_arr[i] + current_char * (arr[i] - len(answer_arr[i]))
                    answer_arr[i] = answer_arr[i + 1]

        for string in answer_arr:
            print(string)


if __name__ == '__main__':
    main()

# runtime error
