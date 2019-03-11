class Solution {
public:
    // bool verifyPreorder(vector<int>& preorder) {
    //     int cur_min = INT_MIN;
    //     int n = preorder.size();
    //     stack<int> s;
    //     // int index = -1;
    //     for(int i=0;i<n;i){
    //         if(s.empty()||s.top()>preorder[i]){
    //             if(preorder[i]<cur_min)return false;
    //             s.push(preorder[i++]);
    //         }
    //         else{
    //             cur_min = s.top();s.pop();
    //         }
    //     }
    //     return true;
    // }
    
     bool verifyPreorder(vector<int>& preorder) {
        int cur_min = INT_MIN;
        int index = -1;
        for(int i=0;i<preorder.size();i){
            if(index==-1||preorder[index]>preorder[i]){
                if(preorder[i]<cur_min)return false;
                preorder[++index]=preorder[i++];
            }
            else cur_min = preorder[index--];
        }
        return true;
    }
 
};