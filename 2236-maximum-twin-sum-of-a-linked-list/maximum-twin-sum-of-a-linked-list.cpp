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
ListNode*revLL(ListNode*head){
    if(head==nullptr){
        return head;
    }
    ListNode*temp=head;
    ListNode*prev=nullptr;
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

        ListNode*newHead=revLL(slow);
        int maxSum=0;
        ListNode*temp=head;
        ListNode*temp2=newHead;

        while(temp2!=nullptr){
            int sum=temp->val+temp2->val;

            maxSum=max(maxSum,sum);
            temp=temp->next;
            temp2=temp2->next;
        }

        return maxSum;
    }
};