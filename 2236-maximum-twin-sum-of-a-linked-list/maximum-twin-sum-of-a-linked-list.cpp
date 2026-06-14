/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode*reverse(ListNode*head){
    if(head==nullptr){
        return head;
    }
    ListNode*prev=nullptr;
    ListNode*temp=head;
    while(temp!=nullptr){
        ListNode*next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;
}
    int pairSum(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*newHead=reverse(slow);
        ListNode*temp1=head;
        ListNode*temp2=newHead;
        int maxSum=INT_MIN;
        while(temp2!=nullptr){
            int currSum=0;
            currSum+=temp1->val+temp2->val;

            maxSum=max(currSum,maxSum);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return maxSum;
    }
};