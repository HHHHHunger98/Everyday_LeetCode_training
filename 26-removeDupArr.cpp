#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res = 1;
        for (int i = 0, j = i+1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j]) 
            {
                continue;
            }else{
                i++;
                res++;
                if(i!=j){
                    int tmp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = tmp;
                }
            }
        }
        
        return nums.size() > 0 ? res : 0;
    }
};

int main() {

    return 0;
}