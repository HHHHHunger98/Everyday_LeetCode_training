#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {

    public:
        static int evalRPN (vector<string>& tokens) {

            stack<string> calculator;
            for (int i = 0; i < tokens.size(); i++)
            {
                if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
                {
                    int right = stoi(calculator.top());
                    calculator.pop();
                    int left = stoi(calculator.top());
                    calculator.pop();
                    if (tokens[i] == "+")
                    {
                        calculator.push(to_string(left + right));
                    }else if (tokens[i] == "-")
                    {
                        calculator.push(to_string(left - right));
                    }else if (tokens[i] == "*")
                    {
                        calculator.push(to_string(left * right));
                    }else if (tokens[i] == "/")
                    {
                        calculator.push(to_string(left / right));
                    }
                }
                else {
                    calculator.push(tokens[i]);
                }
            }
            return stoi(calculator.top());
        }
};
int main () {

    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << Solution::evalRPN(tokens);
    return 0;
}
