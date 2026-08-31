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
bool isLocalMaxima(ListNode*prev,ListNode*temp,ListNode*aNext){
    return (prev->val < temp->val) && (temp->val > aNext->val);
}
bool isLocalMinima(ListNode*prev,ListNode*temp,ListNode*aNext){
    return (prev->val > temp->val) && (temp->val < aNext->val);
}
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int localMaxima=-1;
        int localMinima=INT_MAX;

        int first=-1;
        int last=-1;

        ListNode*prev=head;
        ListNode*temp=prev->next;
        ListNode*aNext=temp->next;

        int pos=2;
        while(aNext!=nullptr){
            if(isLocalMaxima(prev,temp,aNext) || isLocalMinima(prev,temp,aNext)){
                if(first==-1){
                    first=pos;
                }
                else{
                    int distance=pos-last;
                    localMinima=min(localMinima,distance);
                }
                last=pos;
            }
            prev=temp;
            temp=aNext;
            aNext=aNext->next;

            pos++;
        }
        if(first==-1 || first==last){
            return {-1,-1};
        }
        localMaxima=last-first;
        return {localMinima,localMaxima};
    }
};