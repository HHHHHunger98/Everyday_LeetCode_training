#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:

    int climbStairs(int n, unordered_map<int, int>& map){

        if (n == 0 || n == 1)
        {
            return 1;
        }
        // add the n into map if n is not added.
        if (map.find(n) == map.end())
        {
            map[n] = climbStairs(n-1, map) + climbStairs(n-2, map);
        }
        
        return map[n];
    }
    int climbStairs(int n) {
        
        unordered_map<int,int> map;

        return climbStairs(n, map);
    }
};
int main() {
    Solution s;
    cout << s.climbStairs(44);
    return 0;
}