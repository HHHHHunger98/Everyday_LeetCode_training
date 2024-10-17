#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = nums.size() - 1;
        int i = 0;
        while( i <= l)
        {           
            if (nums[i + (l-i)/2] < target)
            {
                i = i + (l-i)/2 + 1;
            }else if (nums[i + (l-i)/2] > target) {
                l = i + (l-i)/2 - 1;
            }else {
                return i + (l-i)/2;
            }
        }       
        return i;
    }
};

int main () {
    return 0;
}