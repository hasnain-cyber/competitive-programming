def main():
    n = int(input())
    obelisk_arr = [tuple(map(int, input().split())) for _ in range(n)]
    clue_arr = [tuple(map(int, input().split())) for _ in range(n)]

    set_arr = []
    for obelisk in obelisk_arr:
        temp_set = set()
        for clue in clue_arr:
            temp_set.add((clue[0] + obelisk[0], clue[1] + obelisk[1]))
        set_arr.append(temp_set)

    intersection_set = set_arr[0]
    for i in range(1, n):
        intersection_set = intersection_set.intersection(set_arr[i])

    for element in intersection_set:
        print(*element)
        break


if __name__ == "__main__":
    main()

# correct
# can be done in O(n) time by summimg the x and y coordinates of the obelisk and the clue and then dividing by n
