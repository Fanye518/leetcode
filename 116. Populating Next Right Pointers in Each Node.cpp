/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public:
    
//     BFS with O(1) space
    
    // Node* connect(Node* root){
    //     // unordered_map<Node*,int>m;
    //     if (root == NULL) return NULL;
    //     Node *pre = root;
    //     Node *cur = NULL;
    //     while(pre->left) {
    //         cur = pre;
    //         // m[cur]=cur->val;
    //         while(cur) {
    //             cur->left->next = cur->right;
    //             if(cur->next) cur->right->next = cur->next->left;
    //             cur = cur->next;
    //         }
    //         pre = pre->left;
    //     }
    //     return root;
    // }
    
    
    // DFS with O(1) space
    
//     void dfs(Node* start, Node* end) {
//         if(start && end) start->next = end;
//         if(start) dfs(start->left, start->right);
//         if(start && end) dfs(start->right, end->left);
//         if(end) dfs(end->left, end->right);
//     }
    
//     Node* connect(Node* root) {
//         if(!root) return root;
//         dfs(root, nullptr);
//         return root;
//     }
    
    
//  BFS   
    
    Node* connect(Node* root){
        if(!root)return root;
        queue<Node*>q;
        q.push(root);
        while(q.size()){
            int qsize = q.size();
            Node *node = q.front();q.pop();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
            // cout<<node->val<<" ";
            for(int i=1;i<qsize;i++){
                node->next = q.front();q.pop();
                node = node->next;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return root;
        
    }
};
