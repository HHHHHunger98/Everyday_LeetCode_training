#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0) return false;
        
        int tmp = x;
        int rev = 0;
        while (tmp > 0)
        {
            rev = rev*10 + tmp % 10;
            tmp /= 10;
        }

        if (rev == x) return true;
        else return false;
    }
};

int main(){

    Solution s;
    return 0;
}