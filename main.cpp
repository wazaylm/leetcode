#include <iostream>
#include <string.h>
#include "treenode.h"
#include <algorithm>
#include <vector>

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
};


int main() {
    int n;
    cin>>n;
    Solution s;
    cout<<s.convertToTitle(n)<<endl;
    return 0;
}