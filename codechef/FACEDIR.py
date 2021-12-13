for _ in range(int(input())):
    t = int(input())
    t = t % 4
    if t == 0:
        print('NORTH')
    elif t == 1:
        print('EAST')
    elif t == 2:
        print('SOUTH')
    else:
        print('WEST')

# correct
