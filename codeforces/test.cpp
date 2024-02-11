#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

// Function to generate permutations and store them in an array
void generatePermutations(std::vector<int>& nums, std::vector<std::vector<int>>& permutations) {
    // Sort the digits to get permutations
    std::sort(nums.begin(), nums.end());

    // Generate permutations and store them in the array
    do {
        permutations.push_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end()));
}

int main() {
    int number = 1234;

    // Convert the number to a vector of digits
    std::vector<int> digits;
    while (number > 0) {
        digits.push_back(number % 10);
        number /= 10;
    }
    std::reverse(digits.begin(), digits.end());

    // Array to store permutations
    std::vector<std::vector<int>> allPermutations;

    // Generate and store permutations in the array
    generatePermutations(digits, allPermutations);

    // Set to store unique differences
    std::set<int> uniqueDifferences;

    // Calculate differences pairwise and store in the set
    for (size_t i = 0; i < allPermutations.size() - 1; ++i) {
        for (size_t j = i + 1; j < allPermutations.size(); ++j) {
            int diff = 0;
            for (size_t k = 0; k < allPermutations[i].size(); ++k) {
                diff = diff * 10 + std::abs(allPermutations[i][k] - allPermutations[j][k]);
            }
            uniqueDifferences.insert(diff);
        }
    }

    // Output the count of unique differences
    std::cout << "Number of unique differences between permutations: " << uniqueDifferences.size() << std::endl;

    return 0;
}
