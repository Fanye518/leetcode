// Monotonic stack for 2d array
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size() || !matrix[0].size())return 0;
        int m = matrix.size(), n = matrix[0].size();
        
        int res=0;
        stack<int> s;
        vector<int> v = vector<int>(n+1,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<=n;j++){
                if(j<n)v[j] = matrix[i][j]=='1' ? v[j]+1 : 0;
                while(!s.empty()&&v[j]<=v[s.top()]){
                    int pos = s.top();
                    s.pop();
                    res = max(res,v[pos]*(s.empty()?j:j-s.top()-1));
                }
                if(j<n)s.push(j);
            }
        }
        return res;
    }
    
};