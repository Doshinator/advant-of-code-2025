#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "day2.h"

long long SolutionDay2::appears_twice(long long& num) { 
    std::string num_str = std::to_string(num);
    if (num_str.size() % 2 != 0) return 0;

    int mid = num_str.size() / 2;
    std::string first_half = num_str.substr(0, mid);
    std::string sec_half = num_str.substr(mid);

    return first_half == sec_half ? num : 0;
}

long long SolutionDay2::part_one() {
    std::ifstream file("input.txt");
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Failed to open file\n";
        return -1;
    }

    // Read the single line containing all ranges
    if (!std::getline(file, line)) {
        std::cerr << "File is empty\n";
        return -1;
    }

    std::stringstream ss(line);
    std::string token;

    long long total_invalid_id = 0;
    while (std::getline(ss, token, ',')) {
        size_t dash_pos = token.find('-');
        if (dash_pos == std::string::npos) {
            continue; // skip invalid segment
        }

        long long start = std::stoll(token.substr(0, dash_pos));
        long long end   = std::stoll(token.substr(dash_pos + 1));

        // --- Process one range here ---
        // std::cout << "Processing range: " << start << " - " << end << "\n";

        std::string str_start = std::to_string(start);
        std::string str_end = std::to_string(end);
        
        for (long long i = start; i <= end; i++) {
            total_invalid_id += appears_twice(i);
        }
        
    }

    return total_invalid_id;
}