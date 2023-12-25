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

    int k = 10;
    while (true) {
        std::ofstream inputFile("input.txt"); // Create an input file for the programs
        int n = rand() % k + 1;
        string s;
        for (int i = 0; i < n; i++) s.push_back(rand() % 26 + 'a');
        inputFile << n << " " << k << std::endl;
        inputFile << s << std::endl;
        inputFile.close();

        std::string output1 = runProgram(program1, "input.txt");
        std::string output2 = runProgram(program2, "input.txt");

        // trim the outputs
        output1.erase(std::remove(output1.begin(), output1.end(), '\n'), output1.end());
        output2.erase(std::remove(output2.begin(), output2.end(), '\n'), output2.end());

        if (output1 != output2) {
            std::cout << "Difference found for input: " << n << " " << k << std::endl;
            std::cout << "Input: " << s << std::endl;
            std::cout << std::endl;
            std::cout << "Output of program1: " << output1 << std::endl;
            std::cout << "Output of program2: " << output2 << std::endl;
        }
        // else {
        //     std::cout << "Output of program1: " << output1 << std::endl;
        //     std::cout << "Output of program2: " << output2 << std::endl;
        // }
    }

    return 0;
}
