#include <iostream>

#include <string.h>
#include "treenode.h"
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
//168. Excel Sheet Column Title
    string convertToTitle(int n) {
        string res;
        while(n){
            char t=char((n-1)%26)+'A';
            res=t+res;
            n=(n-1)/26;
        }
        return res;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root =NULL;
        TreeNode* ite=NULL;
        int flag=0;
        for(int i=0;i<nums.size();i++){
            TreeNode* temp =new TreeNode(nums[i]);
            //第一个分支，判定树是否是新树
            if(root==NULL){
                root=temp;
            } else{
                //第二个分支，判定节点的大小
                if(temp->val>root->val){
                    temp->left=root;
                    root=temp;
                }
                else{
                    ite=root;
                    while(ite){
                        if(ite->right==NULL){
                            ite->right=temp;
                            ite=NULL;
                        }
                        else{
                            if(ite->right->val < temp->val){
                                temp->left=ite->right;
                                ite->right=temp;
                                ite=NULL;
                            }
                            else{
                                ite=ite->right;
                            }
                        }
                    }
                }
            }
        }
        return root;
    }
//461 hamming distance
    int hammingDistance(int x, int y) {
        int t =x^y;
        int sum=0;
        while(t){
            t=t&(t-1);
            sum++;
        }
        return sum;
    }
//judge route circle
    bool judgeCircle(string moves) {
        int rl=0;//right and left move
        int ud=0;//up and down move
        //right=1,left=-1,up=1.down=-1
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='R')
                rl+=1;
            if(moves[i]=='L')
                rl+=-1;
            if(moves[i]=='U')
                ud+=1;
            if(moves[i]=='D')
                ud+=-1;
        }
        return (!rl)&&(!ud);
    }

    //617. Merge Two Binary Trees
    //先序遍历
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1&&!t2) return t1;
        if(!t1&&t2) return t2;
        if(!t1&&!t2) return NULL;
        TreeNode* root = new TreeNode(t1->val+t2->val);
        root->left=mergeTrees(t1->left,t2->left);
        root->right=mergeTrees(t1->right,t2->right);
        return root;
    }
};


int main() {
    int n;
    cin>>n;
    Solution s;
    cout<<s.convertToTitle(n)<<endl;

    return 0;
}