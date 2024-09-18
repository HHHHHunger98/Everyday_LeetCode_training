#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{

    public:
        static string kthDistinct(vector<string>& arr, int k) {

            // 暴力解法
            // 首先找到所有的distinct strings
            string res = "";
            vector<string> distinctStrs;
            for (int i = 0; i < arr.size(); i++)
            {
                distinctStrs.push_back(arr[i]);
                for (int j = 0; j < arr.size(); j++)
                {
                    if (arr[i] == arr[j])
                    {
                        distinctStrs.pop_back();
                        break;
                    }
                }
            }

            if (k < distinctStrs.size()) res = distinctStrs.at(k-1);
            return res;
        }
};

int main() {

    vector<string> arr = {"d","b","c","b","c","a"};
    cout << Solution::kthDistinct(arr,2) << endl;
    return 0;
}