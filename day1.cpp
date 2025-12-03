#include <iostream>
#include "day1.h"

int Solution::positive_dial(int &curr, int val) {
    return (curr + val) % 100;
}

int Solution::negative_dial(int &curr, int val) {
    return (curr - val) % 100;
}

int Solution::part_one() {
    int curr = 50;
    int count = 0;

    std::ifstream file("input.txt");
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        char turn = line[0];
        int value = std::stoi(line.substr(1));

        if (turn == 'R') {
            curr = positive_dial(curr, value);
        } else if (turn == 'L') {
            curr = negative_dial(curr, value);
        }

        if (curr == 0)
            count++;
    }
    
    std::cout << count << std::endl;
    return count;
}

int Solution::part_two() {
    int curr = 50;
    int count = 0;

    std::ifstream file("input.txt");
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        char turn = line[0];
        int value = std::stoi(line.substr(1));

        for (int i = 0; i < value; i++) {
            if (turn == 'R') {
                curr = positive_dial(curr, 1);
            } else if (turn == 'L') {
                curr = negative_dial(curr, 1);
            }

            if (curr == 0)
                count++;
        }
    }

    std::cout << count << std::endl;
    return count;
}
