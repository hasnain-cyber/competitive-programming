def main():
    for _ in range(int(input())):
        s, t, p = input(), input(), input()

        p_dict = {}
        for char in p:
            if char in p_dict:
                p_dict[char] += 1
            else:
                p_dict[char] = 1

        flag = True
        for i in range(len(t)):
            if i + 1 > len(s) or s[i] != t[i]:
                if t[i] not in p_dict or p_dict[t[i]] == 0:
                    flag = False
                    break
                else:
                    s = s[:i] + t[i] + s[i:]
                    p_dict[t[i]] -= 1
        if s != t:
            flag = False

        print("YES" if flag else "NO")


if __name__ == "__main__":
    main()

# correct
