#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
class MyQue {
    public:
        deque<int> myque;
        
        void pop (int value) {
            if (!myque.empty() && value == myque.front())
            {
                myque.pop_front();
            }
        }

        void push (int value) {
            while (!myque.empty() && myque.back() < value)
            {
                myque.pop_back();
            }
            myque.push_back(value);
        }

        int front () {
            return myque.front();
        }
};
class Solution {
    public:
        static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            MyQue slidMax;
            vector<int> result;

            for (int i = 0; i < k; i++)
            {
                slidMax.push(nums[i]);
            }

            result.push_back(slidMax.front());

            for (int i = k; i < nums.size(); i++)
            {
                slidMax.pop(nums[i-k]);
                slidMax.push(nums[i]);
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