#include <iostream>
#include <fstream>
#include <string>
using namespace std;



class Solution {
public:
    int positive_dial(int &curr, int val) {
        return (curr + val) % 100;
    }

    int negative_dial(int &curr, int val) {
        return (curr - val) % 100;
    }

    int part_one() {
        int curr = 50;
        int count = 0;

        std::ifstream file("input.txt");
        std::string line;

        while (std::getline(file, line)) {
            if (line.empty()) continue;

            char turn = line[0]; // L or R
            int value = std::stoi(line.substr(1)); // the number
            // std::cout << turn << " : " << value << std::endl;

            if (turn == 'R') {
                curr = positive_dial(curr, value);
            }
            if (turn == 'L') {
                curr = negative_dial(curr, value);
            }

            count += (curr == 0) ? 1 : 0;
        }
        
        cout << count << endl;    
        return count;
    }

    int part_two() {
        int curr = 50;
        int count = 0;
        std::ifstream file("input.txt");
        std::string line;

        int n_clicks = 0;
        while (std::getline(file, line)) {
            if (line.empty()) continue;

            char turn = line[0]; // L or R
            int value = std::stoi(line.substr(1)); // the number
            // std::cout << turn << " : " << value << std::endl;
            
            for (int i = 0; i < value; i++) {
                if (turn == 'R') {
                    curr = positive_dial(curr, 1);
                }
                if (turn == 'L') {
                    curr = negative_dial(curr, 1);
                }
                
                count += (curr == 0) ? 1 : 0;
            }
        }

        cout << count << endl;
        return count;
    }
};


int main() {
    Solution solution;
    // solution.part_one();
    solution.part_two();

    return 0;
}