def hexToBinary(hex_string):
    return "{0:08b}".format(int(hex_string, 16))


def main():
    for _ in range(int(input())):
        k = int(input())
        a, b, c = hexToBinary(input()), hexToBinary(input()), hexToBinary(input())


# solving
