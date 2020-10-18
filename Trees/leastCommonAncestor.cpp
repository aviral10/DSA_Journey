/*
Author: Aviral
*/
// Least Common Ancestor of 2 nodes in a binary tree
// LeetCode problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        
        if(root == p || root == q) return root;
        
        TreeNode*l = lowestCommonAncestor(root->left, p, q);
        TreeNode*r = lowestCommonAncestor(root->right, p, q);
        
        //Case 1: Something was found on the left as well as right
        //This means current node is common ancestor
        if(l && r) return root;

        //If one of the side is empty
        //This means a common ancestor was already found somewhere below so return that
        return l ? l : r;
    }
};