#include <iostream>
#include "day1.h"
#include "day2.h"
#include "day3.h"

int main() {
    SolutionDay2 s;
    std::cout << "=== Day 2 ===" << std::endl;

    std::cout << "Part One Result: ";
    std::cout << s.part_one() << std::endl;


    std::cout << "=== Day 3 ===" << std::endl;
    SolutionDay3 s3;
    std::cout << "Part One Result: ";
    std::cout << s3.part_one() << std::endl;

    return 0;
}