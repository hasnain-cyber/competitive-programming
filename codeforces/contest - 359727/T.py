def build_tree(arr, depth_arr, current_depth):
    pass


def main():
    for _ in range(int(input())):
        length = int(input())
        arr = list(map(int, input().split()))
        depth_arr = [0 for i in range(length)]
        current_depth = 0
        build_tree(arr, depth_arr, current_depth)


if __name__ == "__main__":
    main()

# could not solve
