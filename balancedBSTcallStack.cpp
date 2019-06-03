// Runtime: 4 ms, faster than 95.36% of C++ online submissions for Palindrome Permutation.
// Memory Usage: 8.3 MB, less than 36.72% of C++ online submissions for Palindrome Permutation.

/*
110. Balanced Binary Tree
Easy

1218

108

Favorite

Share
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   7
  / \
 4   5

Return false.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int getHeight(TreeNode* root)
{
    if (root == NULL) return 0;
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    return max(l, r) + 1;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        if (root == NULL) return true;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        return (abs(l - r) < 2 && isBalanced(root->left) && isBalanced(root->right));
    }
};

// Runtime: 12 ms, faster than 96.89% of C++ online submissions for Balanced Binary Tree.
// Memory Usage: 17.6 MB, less than 14.42% of C++ online submissions for Balanced Binary Tree.


Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   7
  / \
 4   5

 Level 0
 ---------
 val = 1 (not NULL)
 l =                bp-l0 -> getHeight(root->left)
 r =

Level 1 (getHeight Level 0)
----------
val = 2 (not NULL)
l =                 bp-l1 -> getHeight(root->left)
r =

Level 2 (getHeight Level 1)
----------
val = 3 (not NULL)
l =                 bp-l2 -> getHeight(root->left)
r =

Level 3 (getHeight Level 2)
----------
val = 4 (not NULL)
l =                 bp-l3 -> getHeight(root->left)
r =

Level 4 (getHeight Level 3)
----------
root = NULL return 0

Level 3 (getHeight Level 2)
----------
val = 4 (not NULL)
l = 0
r =                 bp-r3 -> getHeight(root->right)

Level 4 (getHeight Level 3)
----------
root = NULL return 0

Level 3 (getHeight Level 2)
----------
val = 4 (not NULL)
l = 0
r = 0
return max(l, r) + 1 = 1

Level 2 (getHeight Level 1)
----------
val = 3 (not NULL)
l = 1
r =                 bp-r2 -> getHeight(root->right)

Level 3 (getHeight Level 2)
----------
val = 5 (not NULL)
l =                 bp-l3 -> getHeight(root->left)
r = 

Level 4 (getHeight Level 3)
----------
root = NULL return 0

Level 3 (getHeight Level 2)
----------
val = 5 (not NULL)
l = 0
r =                 bp-r3 -> getHeight(root->right)

Level 4 (getHeight Level 3)
----------
root = NULL return 0

Level 3 (getHeight Level 2)
----------
val = 5 (not NULL)
l = 0
r = 0              
return max(l, r) + 1 = 1

Level 2 (getHeight Level 1)
----------
val = 3 (not NULL)
l = 1
r = 1
return max(l, r) + 1 = 2

Level 1 (getHeight Level 0)
----------
val = 2 (not NULL)
l = 2
r =                 bp-r1 -> getHeight(root->right)

Level 2 (getHeight Level 1)
----------
val = 7 (not NULL)
l =                 bp-l2 -> getHeight(root->left)
r = 

Level 3 (getHeight Level 2)
----------
root = NULL return 0


       1
      / \
     2   2
    / \
   3   7
  / \
 4   5

Level 2 (getHeight Level 1)                 
----------
val = 7 (not NULL)
l = 0               
r = 0

return 1

Level 1 (getHeight Level 0)
----------
val = 2 (not NULL)
l =  2
r =  1
return 3

Level 0 
----------
val = 1 (not NULL)
l = 3
r = 1                 getHeight(root->right) returns 1
return (abs(l - r) < 2 && isBalanced(root->left) bp

Level 1














