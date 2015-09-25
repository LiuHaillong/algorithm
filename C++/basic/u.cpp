#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> num;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        while(right<n){
        	if(nums[right]!=0 && nums[left]==0){
        		swap(nums[right],nums[left]);
        		left++;
			}
			if(nums[left]!=0)
				left++;
			right++;
		}
    }
};

int main(){
	num.push_back(0);
	num.push_back(1);
	num.push_back(0);
	num.push_back(3);
	num.push_back(12);
	Solution s;
	s.moveZeroes(num);
	
	for(int i=0;i<num.size();i++)
		printf("%d",num[i]);
	printf("\n");
	getchar();
	return 0;
}
