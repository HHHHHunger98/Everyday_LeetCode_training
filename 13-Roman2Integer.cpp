#include <iostream>
#include <string>

using namespace std;

class Solution{

    public:
        int romanToInt(string s){
            
            int res = 0;
            int pri = 0, cur = 0;
            for (int i = 0; i < s.length(); i++)
            {   
                switch (s[i])
                {
                case 'I':
                    cur = 1;
                    break;
                case 'V':
                    cur = 5;
                    break;
                case 'X':
                    cur = 10;
                    break;
                case 'L':
                    cur = 50;
                    break;
                case 'C':
                    cur = 100;
                    break;
                case 'D':
                    cur = 500;
                    break;
                case 'M':
                    cur = 1000;
                    break;
                }
                if(pri == 0 || pri >= cur) {
                    res += cur;
                    pri = cur;
                }else if(pri < cur){
                    res -= pri;
                    res -= pri;
                    res += cur;
                }
            }
            return res;
        }
};

int main() {

    Solution s;
    cout << s.romanToInt("MCMXCIV") << endl;
    return 0;
}