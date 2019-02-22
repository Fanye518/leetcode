// 中序遍历 发现非递增时保存两个node
// 最后只要把最大和最小的node交换val

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> vNode;
    TreeNode* prev = new TreeNode(INT_MIN);
    void traverse(TreeNode* root){    
        if(!root)return;
        traverse(root->left);
        if(prev->val>root->val){
            vNode.push_back(root);
            vNode.push_back(prev);
        }
        prev = root;
        traverse(root->right);
        
        
    }
    void recoverTree(TreeNode* root) {
        if(!root)return;
        traverse(root);
        if(vNode.size()==2)
            swap(vNode[0]->val,vNode[1]->val);
        else if (vNode.size()==4){
            if(vNode[0]->val>vNode[2]->val)
                swap(vNode[1]->val,vNode[2]->val);
            else swap(vNode[0]->val,vNode[4]->val);
        }
    }
};