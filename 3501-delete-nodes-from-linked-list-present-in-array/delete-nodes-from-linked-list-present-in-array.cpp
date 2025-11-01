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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>result(nums.begin(),nums.end());

        ListNode*dummy=new ListNode(0);
        dummy->next=head;

        ListNode*temp=head;
        ListNode*ans=dummy;

        while(temp!=nullptr){
            if(result.count(temp->val)){
                ans->next=temp->next;
            }
            else{
                ans=temp;
            }
            temp=temp->next;
        }
        return dummy->next;
        
    }
};