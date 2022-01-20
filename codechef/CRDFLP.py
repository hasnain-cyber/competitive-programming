def main():
    for _ in range(int(input())):
        n = int(input())
        front_arr = list(map(lambda x: "{:032b}".format(int(x)), input().split()))
        back_arr = list(map(lambda x: "{:032b}".format(int(x)), input().split()))

        for bit_index in range(32):
            flip_counter = 0
            break_flag = False

            if front_arr[0][bit_index] == "1":
                ans = int(front_arr[0], 2)
            elif back_arr[0][bit_index] == "1":
                ans = int(back_arr[0], 2)
                flip_counter += 1
            else:
                continue

            for i in range(1, n):
                if front_arr[i][bit_index] == "1":
                    ans &= int(front_arr[i], 2)
                elif back_arr[i][bit_index] == "1":
                    ans &= int(back_arr[i], 2)
                    flip_counter += 1
                else:
                    break_flag = True
                    break

            if break_flag or bit_index == 31:
                print(0, 0)
            else:
                print(ans, flip_counter)
                break


if __name__ == "__main__":
    main()

# wrong answer, can't figure out why
