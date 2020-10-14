/*
Author : Aviral
*/

//Leet Code problem: https://leetcode.com/problems/diameter-of-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    pair<int, int> diameter(TreeNode *root){
        if(root == NULL){
            return {0,0};
        }
        //Solve subproblem on left sub tree as well as right sub tree;
        pair<int, int> ll  = diameter(root->left);
        pair<int, int> rr = diameter(root->right);
        
        int mh,ti;
        //mh is for max_height and ti stands for "This is It"
        //signifying that if connecting current node makes the longest path or not
        mh = max(ll.first, rr.first) + 1;
        ti = max(ll.first + rr.first+1, max(ll.second, rr.second));
        return {mh, ti};
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans = diameter(root);
        return ans.second-1 < 0 ? 0 : ans.second-1;
    }
};
