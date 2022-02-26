def main():
    for _ in range(int(input())):
        n = int(input())
        preference_dict = {}
        for i in range(1, n + 1):
            preference_dict[i] = input().split()[1:]

        availibility_arr = [True for i in range(n + 1)]

        unmarried_princess = None
        for i in range(1, n + 1):
            flag = False
            for desired_prince in preference_dict[i]:
                if availibility_arr[int(desired_prince)]:
                    availibility_arr[int(desired_prince)] = False
                    flag = True
                    break
            if not flag:
                unmarried_princess = i

        if unmarried_princess:
            print("IMPROVE")
            for i in range(1, n + 1):
                if availibility_arr[i]:
                    print(unmarried_princess, i)
                    break
        else:
            print("OPTIMAL")


if __name__ == "__main__":
    main()

# correct
