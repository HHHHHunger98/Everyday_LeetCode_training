#include <iostream>
#include <iterator>
#include <string>
#include <stack>

using namespace std;

class Solution{

    public:
        static string removeDuplicates (string s) {

            stack<char> checker;

            for (int i = 0; i < s.size() ; i++) {
                if (checker.empty() || checker.top() != s[i]) {
                    checker.push(s[i]);
                }
                else if (checker.top() == s[i]) {
                    checker.pop();
                }
            }
            string result(checker.size(),' ');
            for (int i = checker.size() - 1; i >= 0; i--) {
                result[i] = checker.top();
                checker.pop();
            }
            return result;
        }
};

int main () {

    cout << Solution::removeDuplicates("abbbabaaa");
    return 0;
}