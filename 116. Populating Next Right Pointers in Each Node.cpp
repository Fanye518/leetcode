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
    Node* connect(Node* root){
        if (root == NULL) return NULL;
        Node *pre = root;
        Node *cur = NULL;
        while(pre->left) {
            cur = pre;
            while(cur) {
                cur->left->next = cur->right;
                if(cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
        return root;
    }

};

// class Solution {
//     private: Node *prev,*head;
// public:
//     void inorder(Node* root){
//         if(root->left && root->right){
//             inorder(root->left);
//             prev->next = root;
//             prev = root;
//             inorder(root->right);
//         }
//         else{
//             if(prev){
//                 prev->next = root;
//                 prev = root;
//             }
//             else {
//                 prev = root;
//                 head = root;
//             }
//         }
//     }
//     Node* connect(Node* root) {
//         if(!root)return root;
//         prev = NULL;
//         inorder(root);
//         while(head->next){
//             Node* temp = head->next;
//             Node* slow = head;
//             Node *fast,*slow_next;
//             while(slow_next=slow->next){
//                 fast = slow->next->next;
//                 slow->next = fast;
//                 slow = slow_next;
//             }  
//             head = temp;
//         }
//         return root;
//     }
// };