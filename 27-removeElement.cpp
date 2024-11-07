#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0, j = nums.size() - 1;
        for (int i = 0; i <= j; i++)
        {
            if (nums[i] != val)
            {
                k++;
            } else {
                nums[i] = nums[j];
                j--;
                i--;
            }
        }

        return k;
    }
};

int main() {

    return 0;
}