#pragma once
#include <string>
#include <fstream>

class Solution {
public:
    int positive_dial(int &curr, int val);
    int negative_dial(int &curr, int val);

    int part_one();
    int part_two();
};