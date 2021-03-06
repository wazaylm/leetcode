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


    //561. Array Partition I
    int arrayPairSum(vector<int>& nums) {
        int res=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=2){
            res+=nums[i];
        }
        return res;
    }

    //537. Complex Number Multiplication
    string complexNumberMultiply(string a, string b) {
        int a1,a2,b1,b2;
        int r1,r2;
        string res;
        a1=stoi(a.substr(0,a.find('+')));
        a2=stoi(a.substr(a.find('+')+1,a.find('i')));

        b1=stoi(b.substr(0,b.find('+')));
        b2=stoi(b.substr(b.find('+')+1,b.find('i')));

        r1=a1*b1-a2*b2;
        r2=a1*b2+a2*b1;

        res=to_string(r1)+'+'+to_string(r2)+'i';
        return res;

    }

    //419. Battleships in a Board
    int countBattleships(vector<vector<char>>& board) {
        int res=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='X'){
                    if(i==0){
                        if(j==0) res++;
                        else if(board[i][j-1]=='.')
                            res++;
                    } else{
                        if(j==0){
                            if(board[i-1][j]=='.') res++;
                        } else {
                            if(board[i-1][j]=='.'&&board[i][j-1]=='.')
                                res++;
                        }
                    }
                }
            }
        }
        return res;
    }

    vector<int> countBits(int num) {
        vector<int> res;
        int flag=0;
        int mul=1;
        for (int i = 0; i <=num ; ++i) {
            if(i==0)
                res.push_back(0);
            else{
            int t=i&(i-1);
            if(t==0){
                flag=i;
                res.push_back(1);
            } else{
                res.push_back(res[i-flag]+1);
            }
            }
        }
        return res;
    }

    //476. Number Complement
    int findComplement(int num) {
        int d=num&(num-1);
        int t;
        if(d==0) return num-1;
        else{
            while(d){
                t=d;
                d=d&(d-1);
            }
            t=t|(t-1);
            return (~num)&t;
        }
    }
//    //476. Number Complement的第二种解法
//    int findComplement2(int num) {
//        int r,s=0,t=0;
//        while(num){
//            r = num % 2;
//            num /= 2;
//            s += pow(2,t) * (1-r);
//            t++;
//        }
//        return s;
//    }

    string reverseWords(string s) {
        string res;
        while(s.find(' ')!=string::npos){
            string temp=s.substr(0,s.find(' '));
            s.erase(0,s.find(' ')+1);
            reverse(temp.begin(),temp.end());
            res+=temp;
            res.push_back(' ');
        }
        reverse(s.begin(),s.end());
        res+=s;
        return res;
    }

};


int main() {
    int t;
    cin>>t;
    Solution s;
    cout<<s.findComplement(t);

    return 0;
}