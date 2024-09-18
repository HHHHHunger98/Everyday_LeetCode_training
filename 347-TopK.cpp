#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

    public:
        static vector<int> topKElement(vector<int>& nums, int k) {

            unordered_map<int, int> myMap;
            for (int i = 0; i < nums.size(); i++)
            {   
                myMap[nums[i]]++;
            }
            
        }
};

int main() {

    return 0;
}