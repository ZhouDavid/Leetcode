#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();int n = nums2.size();
		if(m>n) return findMedianSortedArrays(nums2,nums1);
		int left = 0;int right = m;
		while(left<=right){
			int i = (right+left)/2;
			int j = (m+n+1)/2-i;
			if(i<m&&(nums1[i]<nums2[j-1])){
				left = i+1;
			}
			else if(i>0&&(nums1[i-1]>nums2[j])){
				right = i;
			}
			else{
				int max_left;
				int min_right;
				if(i==0){
					max_left = nums2[j-1];
				}
				else if(j==0){
					max_left = nums1[i-1];
				}
				else max_left = maximum(nums1[i-1],nums2[j-1]);
				if(i==m) {
					min_right = nums2[j];
				}
				else if(j==n){
					min_right = nums1[i];
				}
				else{
					min_right = minimum(nums1[i],nums2[j]);
				} 
				if((m+n)%2){
					return max_left;	
				}
				else{
					return double(max_left+min_right)/2;
				}
			}
		}
	}
    
    int maximum(int a,int b){
    	return a>b?a:b; 
	}
    int minimum(int a,int b){
    	return a<b?a:b;
	}
//    double median(vector<int>&array){
//    	int length = array.size();
//    	if(length%2){
//    		int mid_pos = (length-1)/2;
//    		return array[mid_pos];
//		}
//		else{
//			double sum = array[length/2]+array[length/2-1];
//			return sum/2;
//		}
//	}
//	void quicksort(int left,int right,vector<int>& array){
//		if(left==right) return;
//		int j = right-1;
//		int i = left;
//		int k = array[i];
//		while(i!=j){
//			while(array[j]>=k&&i<j)j--;
//			while(array[i]<=k&&i<j)i++;
//			int tmp = array[i];
//			array[i] = array[j];
//			array[j] = tmp;
//		}
//		int tmp = array[i];
//		array[i] = k;
//		array[left] = tmp;
//		quicksort(left,i,array);
//		quicksort(i+1,right,array);
//	}
//	void bubblesort(int left,int right,vector<int>&array){
//		for(int i = 0;i<array.size()-1;i++){
//			for(int j = 0;j<array.size()-1-i;j++){
//				if(array[j]>array[j+1]){
//					int temp = array[j];
//					array[j]=array[j+1];
//					array[j+1]=temp;
//				}
//			}
//		}
//	}
};

int main(){
	int a[]={};
	int b[]={1};
	vector<int> array1(a,a+sizeof(a)/sizeof(int));
	vector<int> array2(b,b+sizeof(b)/sizeof(int));
	Solution solu;
	cout<<solu.findMedianSortedArrays(array1,array2);
	
//	for(int i = 0;i<array.size();i++){
//		cout<<array[i]<<endl;
//	}
	return 0;
} 
