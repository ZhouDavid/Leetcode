#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
    	bool positive=true;
    	if(x<0) {
    		positive=false;
    		x = 0-x;
		}
    	int result = 0;
        while(x>0){
        	if((INT_MAX-x%10)/10<result) return 0;
        	result = result*10+x%10;
        	if(result>INT_MAX) return 0; 
        	x=x/10;
		}
		if(!positive)return(0-result);
		return result;
    }
};




int main(){
	Solution s;
	cout<<s.reverse(123)<<endl;
	return 0;
}
