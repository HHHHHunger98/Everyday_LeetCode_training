#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
    public:

        int findKthNumber(vector<int>& nums1, vector<int>& nums2, int ptr1, int ptr2, int k){
            
            int res;
            return res;
        }

        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
            
            bool even = nums1.size() + nums2.size() % 2 == 0 ? true : false; //判断奇偶性

            int K = (nums1.size() + nums2.size() + 1) / 2;

            double res;

            return res;
        }

        static vector<int> arrayGenerator(int maxLen, int maxVal){

            vector<int> res((int)rand()%maxLen);
            
            for(int i = 0;i < res.size();i++) {
                res[i] = (int)rand()%maxVal;
            }

            sort(res.begin(),res.end());

            return res;
        }
};

int main(){

    int maxlen = 10;
    int maxval = 100;
    srand((unsigned)time(NULL));

    vector<int> n1 = Solution::arrayGenerator(maxlen, maxval);
    vector<int> n2 = Solution::arrayGenerator(maxlen, maxval);

    for (int i = 0; i < n1.size(); i++) {
        cout << n1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n2.size(); i++) {
        cout << n2[i] << " ";  
    }
    cout << endl;

    return 0;
}