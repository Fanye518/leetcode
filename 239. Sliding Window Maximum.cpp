class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        if(!n)return vector<int>();
        vector<int> res(n-k+1,0);
        stack<int> s;
        vector<int> L(n,0), R(n,0);
        nums.push_back(INT_MAX);
        for(int i=0;i<=n;i){
            if(s.empty()||nums[s.top()]>nums[i])s.push(i++);
            else{
                int pos = s.top();s.pop();
                L[pos] = s.empty()?pos:pos-s.top()-1;
                R[pos] = i-pos-1;
            }
        }

        for(int i=0;i<n;i++){
            if(L[i]+R[i]+1<k)continue;
            for(int j=max(i-k+1,i-L[i]);j<min(i+R[i]-k+2,i+k);j++){
                res[j]=nums[i];
            }
        }
        
        return res;
    }
};