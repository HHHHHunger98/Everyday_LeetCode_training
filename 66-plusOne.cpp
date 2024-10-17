#include <vector>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (++digits[digits.size() - 1] < 10) return digits;
        for (int i = digits.size() - 1; i > 0; i--)
        {
            if (digits[i] < 10) return digits;
            if(digits[i] == 10) {
                digits[i-1]++;
                digits[i]-=10;
            }
        }
        vector<int> res;
        if (digits[0] == 10){
            digits[0] = 0;     
            res.push_back(1);
            res.insert(res.end(),digits.begin(),digits.end());
        }
        else return digits;
        
        return res;
    }
};

int main() {

    return 0;
}