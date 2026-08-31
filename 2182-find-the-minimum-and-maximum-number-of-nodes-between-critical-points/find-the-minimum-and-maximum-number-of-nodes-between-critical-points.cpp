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

        int currMaxima=0;
        int currMinima=0;

        ListNode*prev=head;
        ListNode*temp=prev->next;
        ListNode*aNext=temp->next;

        vector<int>points;
        int pos=2;
        while(aNext!=nullptr){
            if(isLocalMaxima(prev,temp,aNext) || isLocalMinima(prev,temp,aNext)){
                points.push_back(pos);
            }
            prev=temp;
            temp=aNext;
            aNext=aNext->next;

            pos++;
        }

        if(points.size() < 2){
            return{-1,-1};
        }
        localMaxima=points.back()-points.front();

        for(int i=1;i<points.size();i++){
            localMinima=min(localMinima,points[i]-points[i-1]);
        }

        return {localMinima,localMaxima};
    }
};