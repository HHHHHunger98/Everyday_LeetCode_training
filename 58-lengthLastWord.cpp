#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int flag = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            cout << s[i] << endl;
            if (s[i] == ' ' && flag == 0) continue;
            if (s[i] != ' ' && flag == 0) flag = 1;
            if (s[i] == ' ' && flag == 1) break;
            if (flag && s[i] != ' ')
            {
                res++;
            }
        }
        
        return res;
    }
};

int main () {

    Solution s;
    cout << s.lengthOfLastWord("Hello World");
    return 0;
}