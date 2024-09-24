#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        string str1 = strs[0];
        bool flag = true;
        for (int i = 0; i < str1.length(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (str1[i] != strs[j][i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                res = str1.substr(0,i+1);
            }
            else{
                res = str1.substr(0,i);
                break;
            }
        }
        return res;
    }
};

int main() {

    Solution s;
    vector<string> strs = {"dogg","dogg","dog"};
    cout << "hello:" <<  s.longestCommonPrefix(strs) << endl;
    return 0;
}