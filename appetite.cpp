//3���˱ȷ�����С��ÿ����˵�����仰�� 
//A��B���ҳԵö࣬C���ҳԵ�һ���ࡣ
//B:A���ҳԵö࣬AҲ��C�Եöࡣ
//C���ұ�B�Եö࣬B��A�Եöࡣ
//��ʵ�ϣ�����ԽС���˽��ĶԵĻ�Խ�ࡣ���̰�������С���3���˵�˳��
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
