#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.size() == 1)
            return num[0];

        int end = num.size();
        int minimum;
        int middle = num.size() / 2;

        //ascending order
        if (num[0] > num[end - 1]) {
            if (num[0] > num[middle]) {
                vector<int> temp;
                for(int index = 1; index <= middle; ++ index)
                    temp.push_back(num[index]);
                return findMin(temp);
            }
            else {
                vector<int> temp;
                for(int index = middle; index < end; ++index)
                    temp.push_back(num[index]);
                return findMin(temp);
            }
        }
        //decending order
        else if (num[0] < num[end - 1])
            return num[0];
    }
};
int main() {
    Solution A;

    int my_array[] = {4, 5, 6, 7, 0, 1, 2};
    vector<int> test;
    test.assign(my_array, my_array + 8);

    cout << A.findMin(test) << endl;

    return 0;
}

