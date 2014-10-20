#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits);
};

vector<int> Solution::plusOne(vector<int> &digits) {
    int adder = 1;
    int end = digits.size();
    int last_digit = digits[end - 1];
    if (last_digit + adder <= 9) {
        digits[end - 1] += adder;
        return digits;
    }
    else {
        int index;
        for(index = end - 1; index >= 0; --index) {
            int plus_result = digits[index] + adder;
            digits[index] = plus_result % 10;
            int reminder = (plus_result - digits[index]) / 10;
            adder = reminder;
            if (adder == 0)
                return digits;
        }

        if (index == -1 && adder != 0) {
            std::vector<int>::iterator it;
            it = digits.begin();
            digits.insert(it, adder);
            return digits;
        }
    }
        
}

int main() {
    Solution A;
    vector<int> myvector;

    int myarray [] = {9, 9, 9};
    myvector.insert (myvector.begin(), myarray, myarray+3);

    vector<int> result = A.plusOne(myvector);

    for(int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";

    cout << endl;

    return 0;
}
