def main():
    n = int(input())
    arr = list(map(int, input().split()))

    current_energy = 0
    total_cost = 0
    for i in range(n - 1):
        energy_needed = arr[i + 1] - arr[i]
        if energy_needed > 0:
            if energy_needed > current_energy:
                total_cost += energy_needed - current_energy
                current_energy = 0
            else:
                current_energy -= energy_needed
        else:
            current_energy -= energy_needed
    print(total_cost + arr[0])


if __name__ == "__main__":
    main()

# correct
