import math


def main():
    radius = 40000 / math.pi
    theta, phi = 0, 0
    for _ in range(int(input())):
        distance, direction = input().split()
        distance = int(distance)

        if direction == "North":
            if theta == 0:
                print("NO")
                return
            else:
                theta += distance / radius
        elif direction == "South":
            if theta == 180:
                print("NO")
                return
            else:
                theta -= distance / radius
        elif direction == "East":
            phi += distance / radius * math.sin(theta)
        elif direction == "West":
            phi -= distance / radius * math.sin(theta)

        theta %= 360
        phi %= 360

    if theta == 0 and phi == 0:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()

# could not solve
