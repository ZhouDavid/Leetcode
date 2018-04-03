#include<iostream>
#include<vector>
using namespace std;

int quickSelect(vector<int>& array,int k){
	int lo = 0;int hi = array.size();
	while(lo!=hi){
		int key = array[lo];
		int i = lo;int j = hi-1;
		while(i!=j){
			while((i<j)&&(array[j]>=key)) j--;
			while(i<j&&array[i]<=key) i++;
			int temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
		int temp = array[i];
		array[i] = array[lo];
		array[lo] = temp;
		
		if(i==k-1){
			return array[i];
		}
		else if(i<k-1){
			lo = i+1;
		}
		else if(i>k-1){
			hi = i;
		}
	}
	return array[lo]; 
}

void quicksort(vector<int>& array,int lo,int hi){
	if(lo==hi) return;
	int key = array[lo];
	int i = lo;int j = hi-1;
	while(i!=j){
		while(i<j&&array[j]>=key) j--;
		while(i<j&&array[i]<=key) i++;
		int temp = array[j];
		array[j] = array[i];
		array[i] = temp;
	}
	int temp = array[i];
	array[i] = array[lo];
	array[lo] = temp;
	quicksort(array,lo,i);
	quicksort(array,i+1,hi);
} 

int main(){
	int a[]={9,8,7,6,5,10,2,-2,3};
	int k = 9;
	vector<int> array(a,a+sizeof(a)/sizeof(int));
	cout<<quickSelect(array,k)<<endl; 
	quicksort(array,0,array.size());
	cout<<array[k-1]<<endl;
	return 0;
} 
