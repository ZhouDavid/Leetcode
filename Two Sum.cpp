#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int>result;
    	for(int i = 0;i<nums.size();i++){
    		for(int j = i+1;j<nums.size();j++){
    			if(nums[i]+nums[j]==target){
					result.push_back(i);
					result.push_back(j);
				}
			}
		} 
        return result;
    }
};

int main(){
	Solution solu;
	int array[]={2,7,11,15};
	vector<int>nums(array,array+sizeof(array)/sizeof(int));
	vector<int>res = solu.twoSum(nums,17);
	for(int i = 0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
	return 0;
}
