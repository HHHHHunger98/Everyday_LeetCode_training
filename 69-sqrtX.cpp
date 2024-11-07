#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int s = 0, e = x, m = (e-s)/2, res = 0;
        long long sq = 0;
        while (s <= e)
        {
            m = s+(e-s)/2;
            sq = m*m;
            if (x == sq)
            {
                return m;
            }
            else if (x < sq) {
                e = m-1;
            }else if (x > sq) {
                res = m;
                s = m+1;
            }
        }
        return res;
    }
};

int main () {

    Solution s;
    cout << s.mySqrt(8);
    return 0;
}