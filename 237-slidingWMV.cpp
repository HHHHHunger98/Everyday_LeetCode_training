#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
    public:
        static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            queue<int> slidMax;
            vector<int> result;
            if (k==1) return nums;
            for (int i = 0; i < k; i++)
            {
                if (slidMax.empty()) slidMax.push(nums[i]);
                else {
                    while (!slidMax.empty() && slidMax.front() < nums[i]) slidMax.pop();
                    if (!slidMax.empty() && slidMax.front() >= nums[i]) slidMax.push(nums[i]);
                    else if (slidMax.empty()) slidMax.push(nums[i]); // in case of all elements are less than nums[i], then push the newest one into the queue
                }
            }
            result.push_back(slidMax.front());

            for (int i = k; i < nums.size(); i++)
            {
                if (nums[i-k] == slidMax.front()) slidMax.pop();              
                if (nums[i] < slidMax.front()) slidMax.push(nums[i]);
                while (!slidMax.empty() && slidMax.front() < nums[i]) slidMax.pop();
                if (!slidMax.empty() && slidMax.front() >= nums[i]) slidMax.push(nums[i]); 
                else if (slidMax.empty()) slidMax.push(nums[i]);

                result.push_back(slidMax.front());
            }

            return result;
        }
};

int main () {

    vector<int> nums = {1,3,1,2,0,5};
    int k = 3;

    vector<int> result = Solution::maxSlidingWindow(nums, k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    
    return 0;
}