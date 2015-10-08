package leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Administrator on 2015/10/8.
 *
 * Given a binary tree, return all root-to-leaf paths.

 For example, given the following binary tree:

    1
 /   \
 2     3
 \
 5
 All root-to-leaf paths are:

 ["1->2->5", "1->3"]
 */
public class BinaryTreePaths {

    public List<String> paths = new ArrayList<String>();

    public List<String> binaryTreePaths(TreeNode root) {
        if(root!=null)
            getPaths(root,String.valueOf(root.val));
        return paths;
    }

    private void getPaths(TreeNode r, String val) {
        if(r.left==null && r.right==null)
            paths.add(val);
        if(r.left!=null)
            getPaths(r.left, val + "->" + r.left.val);
        if(r.right!=null)
            getPaths(r.right,val+"->"+r.right.val);
    }
}
