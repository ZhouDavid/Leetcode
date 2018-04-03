#include <iostream>
#include <string>
using namespace std;
/*I - 1
V - 5
X - 10
L - 50
C - 100
D - 500
M - 1000
If I comes before V or X, subtract 1 eg: IV = 4 and IX = 9
* If X comes before L or C, subtract 10 eg: XL = 40 and XC = 90
* If C comes before D or M, subtract 100 eg: CD = 400 and CM = 900
*/

class Solution {
public:
    int romanToInt(string s) {
    	int answer = 0;
    	for(int i = 0;i<s.size();i++){
    		if(s[i]=='I'){
    			if(i+1<s.size()&&s[i+1]=='V') {answer+=4;i++;}
    			else if(i+1<s.size()&&s[i+1]=='X') {answer+=9;i++;}
    			else {answer+=1;} 
			}
			else if(s[i]=='X'){
				if(i+1<s.size()&&s[i+1]=='L') {answer+=40;i++;} 
				else if(i+1<s.size()&&s[i+1]=='C') {answer+=90;i++;}
				else{answer+=10;} 
			}
			else if(s[i]=='C'){
				if(i+1<s.size()&&s[i+1]=='D') {answer+=400;i++;} 
				else if(i+1<s.size()&&s[i+1]=='M') {answer+=900;i++;}
				else{answer+=100;} 
			}
			else{
				if(s[i]=='V') answer+=5;
				else if(s[i]=='L')answer+=50;
				else if(s[i]=='D') answer+=500;
				else if(s[i]=='M') answer+=1000;
			}
		}
        return answer;
    }
};

int main(){
	Solution s;
	cout<<s.romanToInt("DCXXI");
	return 0;
}

