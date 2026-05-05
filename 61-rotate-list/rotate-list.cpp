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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0){
            return head;
        }
        ListNode*temp=head;
        int count=1;
        while(temp->next!=nullptr){
            count++;
            temp=temp->next;
        }
        temp->next=head;

        k=k%count;
        int n=count-k;
        for(int i=0;i<n;i++){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=nullptr;

        return head;
    }
};