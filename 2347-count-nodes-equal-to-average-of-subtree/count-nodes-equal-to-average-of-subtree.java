/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int helper(TreeNode root,int[]count){
        if(root==null){
            return 0;
        }
        count[0]++;
        int rightSum=helper(root.left,count);
        int leftSum=helper(root.right,count);

        return rightSum+leftSum+root.val;
    }
    public int averageOfSubtree(TreeNode root) {
        if(root==null){
            return 0;
        }

        int result=0;
        int[]count={0};

        int sum=helper(root,count);
        if(sum/count[0]==root.val){
            result++;
        }
        result+=averageOfSubtree(root.left);
        result+=averageOfSubtree(root.right);

        return result;
    }
}