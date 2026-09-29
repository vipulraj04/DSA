/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode head, int k) {
        int count=0;
        ListNode curr=head;
        while(curr!=null){
            count++;
            curr=curr.next;
        }

        int eSize=count/k;
        int gSize=count%k;

        ListNode result[]=new ListNode[k];
        ListNode temp=head;
        for(int i=0;i<k;i++){
            result[i]=temp;

            int size=eSize;


            if(gSize > 0){
                size++;
                gSize--;
            }

            for(int j=1;j<size;j++){
                temp=temp.next;
            }

            if(temp!=null){
                ListNode nxt=temp.next;

                temp.next=null;

                temp=nxt;
            }
        }

        return result;
    }
}