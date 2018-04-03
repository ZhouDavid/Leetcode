#include <iostream>
using namespace std;
class Solution {
public:
	int pow(int a,int b){
		int base = a;
		int answer = 1;
		while(b!=0){
			if(b&1) answer*=base;
			base*=base;
			b>>=1;
		}
		return answer;
	}
	
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x==0) return true;
        int length = 0;
        // get length
        int xx = x;
        while(xx!=0){
        	xx/=10;
        	length++;
		}
		
		int left = 0;int right = 0;
		while(x>0){
			// get most right
			right = x%10;
			// get most right
			int tmp = length-1;
			left = x/pow(10,tmp);
			x = (x%pow(10,tmp))/10;
			length-=2;	
			if(left!=right) return false;
		}
        return true;
    }
};

int main(){
	Solution s;
	cout<<s.isPalindrome(1321);
	return 0;
}
