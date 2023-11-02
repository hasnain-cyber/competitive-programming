#include <bits/stdc++.h>

using namespace std;

// Function to run a C++ program and capture its output
std::string runProgram(const std::string& programPath, const std::string& input) {
    std::string command = programPath + " < input.txt"; // Assuming the program reads input from a file called "input.txt"
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        return "Error running program.";
    }
    char buffer[128];
    std::string result = "";
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != nullptr) {
            result += buffer;
        }
    }
    pclose(pipe);
    return result;
}

int main() {
    const std::string program1 = "./program1"; // Replace with the actual path to your program
    const std::string program2 = "./program2"; // Replace with the actual path to your program

    int n = 5;
    // generate array of length n
    while (true) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 3;
        }
        std::ofstream inputFile("input.txt"); // Create an input file for the programs
        inputFile << n << std::endl;
        for (int i = 0; i < n; ++i) {
            inputFile << arr[i] << " ";
        }
        inputFile.close();

        std::string output1 = runProgram(program1, "input.txt");
        std::string output2 = runProgram(program2, "input.txt");

        if (output1 != output2) {
            std::cout << "Difference found for input: " << n << std::endl;
            std::cout << "Array: ";
            for (int i = 0; i < n; ++i) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
            std::cout << "Output of program1: " << output1 << std::endl;
            std::cout << "Output of program2: " << output2 << std::endl;

            return 0;
        }
    }

    return 0;
}
