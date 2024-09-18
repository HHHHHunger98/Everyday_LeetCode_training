/*
    problem description:

    input: Multiple lines of number pairs (A and B)
    output: The sum of the pairs (A+B)

    case1:
    input : 3 4
            11 40
    output:
            7
            51
    
    focus:
        file stream, read lines from files, type conversion
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Solution
{
public:
    void AplusB1()
    {
        int sum;
        ifstream fs;
        fs.open("test.txt");
        if(fs.is_open())
        {   
            char num;
            string tmp;
            while (fs.get(num))
            {
                if (num == ' ')
                {
                    sum += stoi(tmp);
                    tmp.clear();
                    continue;
                }
                if (num == '\n')
                {   
                    sum += stoi(tmp);
                    cout << sum << endl;
                    sum = 0;
                    tmp.clear();
                    continue;
                }
                tmp.append(string(1,num));
            }
        }  
        fs.close();
    }
};

int main()
{
    Solution s;
    s.AplusB1();
    return 0;
}