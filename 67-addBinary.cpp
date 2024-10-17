#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

        if (a.length() < b.length())
        {
            string tmp = a;
            a = b;
            b = tmp;
        }
        
        int i = a.length() - 1, j = b.length() - 1;
        bool carry = false;
        string res = "";
        
        while (j >= 0)
        {
            if (carry && a[i] != b[j]) {
                res = "0" + res;
            } else if (!carry && a[i] != b[j]) {
                res = "1" + res;
            } else if (!carry && a[i] == b[j] && a[i] == '1') {
                res =  "0" + res;
                carry = true;
            }else if (!carry && a[i] == b[j] && a[i] == '0') {
                res = "0" + res;
                carry = false;
            }else if (carry && a[i] == b[j] && a[i] == '1') {
                res = "1" + res;
            }else if (carry && a[i] == b[j] && a[i] == '0') {
                res = "1" + res;
                carry = false;
            }
            i--;
            j--;
        }
        while (i>=0)
        {
            if (carry && a[i] == '1')
            {
                res = "0" + res;
            }else if (carry && a[i] == '0') {
                res = "1" + res;
                carry = false;
            }else if (!carry) {
                res = a[i] + res;
            }
            i--;
        }
        
        if (i == -1 && carry) return "1" + res;

        return res;
    }
};

int main() {
    return 0;
}