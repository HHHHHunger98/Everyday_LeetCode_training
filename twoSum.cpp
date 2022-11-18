#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
	
	public:
		static void swap(vector<int>& nums, int i, int j){
			int tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		}
		static vector<int> partition(vector<int>& nums, int L, int R){
			vector<int> ptrs(2,0);
			ptrs[0] = L-1;
			ptrs[1] = R+1;
			int i = L;
			int target = nums[R];

			while (i < ptrs[1]){
				if (i < ptrs[1] && nums[i] == target) i++;
				if (i < ptrs[1] && nums[i] < target) {swap(nums, i, ptrs[0] + 1); i++; ptrs[0]++;}
				if (i < ptrs[1] && nums[i] > target) {swap(nums, i, ptrs[1] - 1); ptrs[1]--;}
			}
			return ptrs;
		}
		static void quickSort(vector<int>& nums, int L, int R){
			if(R-L<1) return;
			int toSwap = L + rand() % (R - L + 1);
			swap(nums, toSwap, R);
			vector<int> Mid = partition(nums, L, R);
			quickSort(nums, L, Mid[0]);
			quickSort(nums, Mid[1], R);
		}
		static vector<int> twoSum(vector<int>& nums, int target) {	
			quickSort(nums, 0, nums.size()-1);
			vector<int> res(2);
			int head = 0;
			int tail = nums.size() - 1;
			while(head < tail){
				if (nums[head] + nums[tail] == target) {res[0] = head; res[1] = tail; break;}
				if (nums[head] + nums[tail] < target) {head++; continue;}
				if (nums[head] + nums[tail] > target) {tail++; continue;}
			}
			return res;
		}
};

class comparisonMachine{

	public:
		static vector<int> lenRandomValueRandom(int maxlen, int maxvalue){
			
			vector<int> res(2,0);
			if (maxlen <= 0) return res;
			int len = (int)rand() % maxlen + 1;

			res = vector<int>(len);
			for (int i = 0; i < len;i++){
				res[i] = (int)rand() % maxvalue + 1;
			}

			return res;
		}
};

int main(){

	srand((unsigned)time(NULL));
	vector<int> arr = comparisonMachine::lenRandomValueRandom(100, 100);
	for (int i = 0;i < arr.size();i++){
		cout << arr[i] << " ";
	}

	cout <<arr.size()<< endl;

	vector<int> res = Solution::twoSum(arr, 120);

	for (int i = 0;i < arr.size();i++){
		cout << arr[i] << " ";
	}

	cout<<endl<<res[0]<<" "<<res[1]<<endl;
	return 0;
}
