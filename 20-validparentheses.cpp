/*
    题目描述，括号匹配，利用栈的方法实现对字符串的括号匹配
    Func: bool isValid(string s)
    Discription: check the input string s, return whether it is a valid. 
                 It is valid when the parentheses are matched.
*/

#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {

    public:
        static bool isValid(string s) {

            stack<char> checker; // declare an empty stack
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                {
                    checker.push(s[i]);
                }

                if (s[i] == ')' || s[i] == ']' || s[i] == '}')
                {
                    if (!checker.empty())
                    {
                        if (checker.top() == '(' && s[i] == ')')
                        {
                            checker.pop();
                        }else if (checker.top() == '[' && s[i] == ']')
                        {
                            checker.pop();
                        }else if (checker.top() == '{' && s[i] == '}')
                        {
                            checker.pop();
                        }
                        else return false;
                    }
                    else{
                        return false;
                    } 
                }
            }
            
            return checker.empty(); 
        }
};

int main() {

    string s = "(])";
    cout << Solution::isValid(s);
    return 0;
}