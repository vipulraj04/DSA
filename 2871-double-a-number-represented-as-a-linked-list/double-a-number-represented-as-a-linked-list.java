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
    public ListNode reverse(ListNode head){
        ListNode prev=null;
        ListNode temp=head;
        while(temp!=null){
            ListNode next=temp.next;
            temp.next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
    public ListNode doubleIt(ListNode head) {
        head=reverse(head);
        ListNode temp=head;
        int carry=0;
        while(temp!=null){
            int data=temp.val*2+carry;

            temp.val=data%10;
            carry=data/10;
            temp=temp.next;
        }
        if(carry!=0){
            ListNode newNode=new ListNode(carry);
            ListNode temp2=head;
            while(temp2.next!=null){
                temp2=temp2.next;
            }
            temp2.next=newNode;
        }

        return reverse(head);
    }
}