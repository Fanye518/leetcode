// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
class Solution {
public:
    TreeNode* build(vector<int>& list, int li, int ri ){
        if(ri==li+1)return new TreeNode(list[li]);
        if(ri==li)return NULL;
        int mid = (ri-li)/2 + li;
        TreeNode* res = new TreeNode(list[mid]);
        res->left = build(list, li, mid);
        res->right = build(list,mid+1,ri);
        return res;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)return NULL;
        vector<int> list;
        while(head){
            list.push_back(head->val);
            head=head->next;
        }
        return build(list,0,list.size());
        
    }
};
