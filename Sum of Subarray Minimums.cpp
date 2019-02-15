// Monotone stack
// 遍历vector，若大于top，则push，若小于等于top，则把top位置的左侧和右侧分别记录（左小于右小于等于 则没有重复）
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n=A.size();
        stack<int> stk;
        vector<int>L(n,0),R(n,0);
        A.push_back(INT_MIN);
        
        for(int i=0;i<=n;i){
            if(stk.size()==0 || A[stk.top()]<A[i]) stk.push(i++);
            else{
                int pos = stk.top();
                stk.pop();
                L[pos]= stk.empty()?pos:pos-stk.top()-1;
                R[pos]=i-pos-1;
            }
        }
        
        int mod = 1e9+7;
        int res=0;
        for(int i=0;i<n;i++){
            int num = 1+L[i]+R[i]+L[i]*R[i];
            res =(res+num*A[i]) % mod;
        }
        return res;
        
    }
};