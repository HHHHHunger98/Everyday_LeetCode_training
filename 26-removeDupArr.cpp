#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates1(vector<int>& nums) {
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

    static int removeDuplicates(vector<int>& nums) {

        int res = 0;
        for (long long i = 0; i < nums.size(); i++)
        {
            if (nums[i] != nums[res])
            {   
                res++;
                nums[res] = nums[i];
            }
        }
        
        return ++res;
    }
};

int main() {

    vector<int> test = {1,1,2};
    cout << Solution::removeDuplicates(test) <<endl;
    for (long long i = 0; i < test.size(); i++)
    {
        cout << test[i] << " " ;
    }
    
    return 0;
}