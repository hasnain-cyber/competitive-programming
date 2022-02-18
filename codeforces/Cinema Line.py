def main():
    n = int(input())
    arr = list(map(int, input().split()))

    amount_dict = {25: 0, 50: 0, 100: 0}
    for money in arr:
        amount_dict[money] += 1
        pay_back = money - 25
        if pay_back == 25:
            if amount_dict[25] > 0:
                amount_dict[25] -= 1
            else:
                print("NO")
                return
        elif pay_back == 75:
            if amount_dict[50] > 0:
                amount_dict[50] -= 1
                if amount_dict[25] > 0:
                    amount_dict[25] -= 1
                else:
                    print("NO")
                    return
            elif amount_dict[25] >= 3:
                amount_dict[25] -= 3
            else:
                print("NO")
                return
    print("YES")


if __name__ == "__main__":
    main()

# correct
