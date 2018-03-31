//3个人比饭量大小，每个人说了两句话： 
//A：B比我吃得多，C和我吃得一样多。
//B:A比我吃得多，A也比C吃得多。
//C：我比B吃得多，B比A吃得多。
//事实上，饭量越小的人讲的对的话越多。请编程按饭量大小输出3个人的顺序。
#include<iostream>
using namespace std;
int main(){
	for(int A = 0;A<3;A++){
		for(int B = 0;B<3;B++){
			for(int C = 0;C<3;C++){
				bool a1 = B>A;
				bool a2 = A==C;
				bool b1 = A>B;
				bool b2 = A>C;
				bool c1 = C>B;
				bool c2 = B>A;
				int a = A+a1+a2;
				int b = B+b1+b2;
				int c = C+c1+c2;
				if(a==2&&b==2&&c==2){
					cout<<"A="<<A<<','<<"B="<<B<<",C="<<C<<endl;
				} 
			}
		}
	}
	return 0;
} 
