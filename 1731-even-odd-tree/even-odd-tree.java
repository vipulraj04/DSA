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
    public boolean isStrictlyIncreasing(List<Integer>level){
        int n=level.size();
        for(int i=0;i<n;i++){
            if(level.get(i)%2==0){
                return false;
            }

            if(i > 0 && level.get(i) <= level.get(i-1)){
                return false;
            }
        }
        return true;
    }
    public boolean isStrictlyDecreasing(List<Integer>level){
        int n=level.size();
        for(int i=0;i<n;i++){
            if(level.get(i)%2!=0){
                return false;
            }

            if(i > 0 && level.get(i) >= level.get(i-1)){
                return false;
            }
        }
        return true;
    }
    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode>q=new LinkedList<>();
        q.add(root);
        boolean flag=true;
        while(!q.isEmpty()){
            List<Integer>level=new ArrayList<>();
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode temp=q.remove();
                level.add(temp.val);

                if(temp.left!=null){
                    q.add(temp.left);
                }
                if(temp.right!=null){
                    q.add(temp.right);
                }
            }
            if(flag){
                if(!isStrictlyIncreasing(level))
                {
                    return false;
                }

            }
            else{
                if(!isStrictlyDecreasing(level)){
                    return false;
                }
            }
            flag=!flag;
        }

        return true;

    }
}