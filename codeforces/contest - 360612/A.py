def main():
    m, s = list(map(int, input().split()))

    min_sum, max_sum = 1 * m, 9 * m
    if not (min_sum <= s <= max_sum):
        print(-1)
    else:
        max_num = int(f'9{s - 9}')

# could not solve
