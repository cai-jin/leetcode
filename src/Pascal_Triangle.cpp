#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
   void generate(int numRows);
};

void Solution::generate(int numRows) {
        vector< vector<int> > result;
        vector<int> row;
        for(int i = 0; i < numRows; ++i) {
            //the first line
            if (i == 0) {
                row.push_back(1);
                result.push_back(row);
            }
            //the other lines
            else {
                row.push_back(1);
                for(int index = 1; index <= i - 1; ++index) {
                    int temp = result[i - 1][index - 1] + result[i - 1][index];
                    row.push_back(temp);
                }
                row.push_back(1);
                result.push_back(row);
            }
            row.clear();
        }
        return result;
}


int main() {
    Solution A;
    A.generate(10);
    return 0;
}
