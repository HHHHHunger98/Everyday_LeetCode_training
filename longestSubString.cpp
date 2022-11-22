#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Solution {
    public:
        static string strGenerator(int maxlen) {
            int len = (int)rand()%maxlen;
            string res;
            for(int i = len; i > 0; i--) {
                res.append(1,(char)(32+rand()%95));
            }
            cout << res <<endl;
            return res;
        }
        static int lengthOfLongestSubstring(string s) {
            vector<int> character(256,-1);
            int head = 0;
            int res = 0;
            for (int i = 0; i < s.length(); i++)
            {
                if (character[s[i]] != -1 && character[s[i]] >= head)
                {
                    head = character[s[i]] + 1;
                }
                character[s[i]] = i;
                res = res > i - head + 1 ? res : i - head + 1;
            }
            return res;
        }
};
int main() {

    int maxlen = 100;
    srand((unsigned)time(NULL));
    string s1 = Solution::strGenerator(maxlen);
    Solution::lengthOfLongestSubstring(s1);
    return 0;
}