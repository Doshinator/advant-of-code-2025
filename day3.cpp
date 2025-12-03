#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "day3.h"

int SolutionDay3::part_one() {
    int total_voltage = 0;

    std::ifstream file("input.txt");
    std::string line;

   if (!file.is_open()) {
        std::cerr << "Failed to open file\n";
        return -1;
    }

    while (std::getline(file, line)) {
        int max_pair = 0;
        for (size_t i = 0; i < line.size(); i++) {
            for (size_t j = i + 1; j < line.size(); j++) {
                max_pair = std::max(max_pair, (line[i] - '0') * 10 + (line[j] - '0'));
                // std::cout << max_pair << " ";
            }
        }
        total_voltage += max_pair;
    }
    
    return total_voltage;
}
