//
// Created by hbzhao on 2017/11/4.
//leetcode中的树节点定义
//
#include <iostream>
#ifndef LEETCODE_TREENODE_H
#define LEETCODE_TREENODE_H
struct TreeNode {
        int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
#endif //LEETCODE_TREENODE_H
