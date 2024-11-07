#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if (nums2.size() == 0)
        {
            return;
        }

        queue<int> q;
        for (int i = 0, j = 0; i < m + n; i++)
        {
            if (i < m) q.push(nums1[i]);

            if ((!q.empty() && q.front() <= nums2[j]) || (!q.empty() && j >= n)) {
                nums1[i] = q.front();
                q.pop();
            } else if ((!q.empty() && q.front() > nums2[j]) || (q.empty() && j < n))
            {   
                nums1[i] = nums2[j];
                j++;
            }
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if (nums2.size() == 0)
        {
            return;
        }
        
        int a = m - 1, b = n - 1;
        for (int i = m+n-1; i >= 0; i--)
        {
            if (a < 0 && b >= 0)
            {
                nums1[i] = nums2[b--];
            } else if (a >= 0 && b < 0)
            {
                nums1[i] = nums1[a--];
            } else if (a >= 0 && b >= 0)
            {
                if (nums1[a] >= nums2[b])
                {
                    nums1[i] = nums1[a--];
                } else if (nums1[a] < nums2[b]) {
                    nums1[i] = nums2[b--];
                }
            }
        }
    }
};

int main() {

    vector<int> nums1 = {2,0}, nums2 = {1};
    Solution s;
    s.merge1(nums1, 1, nums2, 1);
    for (int i : nums1)
    {
        cout << i << " "<<endl;
    }

    return 0;
}