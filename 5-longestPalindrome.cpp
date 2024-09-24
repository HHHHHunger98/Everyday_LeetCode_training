#include <iostream>

using namespace std;

class Solution{

    public: 
        bool isPalindrome(string& s, int head, int tail){
            for (int i = 0; i < (tail - head) / 2 + 1; i++)
            {
                if(s[i+head] != s[tail-i]) return false;
            }
            return true;
        }
        string longestPalindrome(string s) {
            int len = 0;
            int beg = 0 , ed = 0;
            for (int i = 0; i < s.length(); i++)
            {
                for (int j = i+1; j < s.length(); j++)
                {
                    if (isPalindrome(s, i, j) && len <= j - i + 1)
                    {
                        len = j - i + 1;
                        beg = i;
                        ed = j;
                    }
                }
            }
            if (beg <= ed)
            {
                return s.substr(beg,(ed-beg+1));
            }
            else return "";
        }
};

int main() {

    Solution s;
    cout << s.longestPalindrome("bbb") << endl;
    return 0;
}