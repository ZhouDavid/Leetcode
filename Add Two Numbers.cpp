#include<iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	bool jinwei = false;
    	ListNode* result = new ListNode(-1);
    	ListNode* result_copy = result;
        while(l1!=NULL || l2!=NULL){
        	int digit = 0;
        	if(l1!=NULL) {
 				digit+=l1->val;    
			}
        	if(l2!=NULL) {
        		digit+=l2->val;	
			}
        	if(jinwei) digit+=1;
        	if(digit>9){
        		jinwei = true;
        		digit -=10;
			}
			else jinwei = false;
			result->next = new ListNode(digit);
			result = result->next;
			if(l1)l1 = l1->next;
			if(l2)l2 = l2->next;
		}
		if(jinwei){
			result->next = new ListNode(1);
		}
		return result_copy->next;
    }
};

void printListNodes(ListNode* answer){
	ListNode* answer_copy = answer;
	while(answer_copy){
		cout<<answer_copy->val<<' ';
		answer_copy = answer_copy->next;
	}
}
int main(){
	Solution solu;
	ListNode* l1 = new ListNode(2);
	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(8);
	ListNode* result = solu.addTwoNumbers(l1,l2);
	printListNodes(result);
	return 0;
}
