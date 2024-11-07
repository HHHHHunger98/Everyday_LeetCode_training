#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {
        int res = 0, t = 0, last = nums[0];
        for (int i = 0;i < nums.size();i++)
        {
            if (last != nums[i])
            {
                nums[res] = nums[i];
                res++;
                t = 1;
                last = nums[i];
            }else if (last == nums[i]){
                if (t < 2)
                {
                    nums[res] = nums[i];
                    res++;
                    t++;
                }else if (t == 2)
                {
                    continue;
                }
            }
        }
        return res;
    }
};
//[1,1,1,2,2,3]
int main() {

    vector<int> test = {1,1,1,2,2,3};
    cout << Solution::removeDuplicates(test)<<endl;
    for (int i = 0; i < test.size(); i++)
    {
        cout << test[i] << " ";
    }
    
    return 0;
}