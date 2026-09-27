#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include <iomanip>

struct TestResult {
    std::string name;
    int         lineCount;
    bool        passed;
    double      timeMs;
};

bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++)
        if (arr[i] < arr[i - 1]) return false;
    return true;
}

template <typename T>
TestResult runFile(const std::string& filepath, T& solution) {
    std::ifstream file(filepath);
    TestResult result{ filepath, 0, true, 0.0 };

    if (!file.is_open()) {
        std::cerr << "[ERROR] Cannot open: " << filepath << "\n";
        result.passed = false;
        return result;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        result.lineCount++;

        std::vector<int> arr;
        std::istringstream iss(line);
        int num;
        while (iss >> num) arr.push_back(num);

        auto start = std::chrono::high_resolution_clock::now();
        solution.sort(arr);
        auto end   = std::chrono::high_resolution_clock::now();
        result.timeMs += std::chrono::duration<double, std::milli>(end - start).count();

        if (!isSorted(arr)) {
            result.passed = false;
            std::cerr << "  [FAIL] line " << result.lineCount
                      << " -> not sorted correctly\n";
        }
    }
    return result;
}

template <typename T>
void runAll(const std::vector<std::string>& files, T& solution) {
    std::cout << "\n========== SORT TEST RUNNER ==========\n\n";

    int totalPass = 0, totalFail = 0;

    for (const auto& file : files) {
        TestResult r = runFile(file, solution);

        std::cout << (r.passed ? "[PASS]" : "[FAIL]")
                  << "  " << std::left << std::setw(30) << r.name
                  << "  lines: " << std::setw(4) << r.lineCount
                  << "  time: " << std::fixed << std::setprecision(3)
                  << r.timeMs << " ms\n";

        r.passed ? totalPass++ : totalFail++;
    }

    std::cout << "\n======================================\n";
    std::cout << "Results: " << totalPass << " passed, "
              << totalFail << " failed\n\n";
}
