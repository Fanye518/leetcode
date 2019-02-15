class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>stk;
        stk.push_back(-1);
        int res=0;
        for(int i=0;i<height.size();i++){
            if(stk.size()==1 and stk.back()<=height[i]){
                stk.pop_back();
                stk.push_back(height[i]);
            }
            else if(stk.back()>=height[i]){
                stk.push_back(height[i]);
            }
            else if(stk.back()<height[i]){
                if(stk[0]<=height[i]){
                    for(int j=1;j<stk.size();j++){
                        res+=stk[0]-stk[j];
                    }
                    stk.clear();
                    stk.push_back(height[i]);
                    continue;
                }
                for(int j=stk.size()-2;j>=0;j--){
                    if(stk[j]>=height[i]){
                        for(int k=j+1;k<stk.size();k++){
                            res +=height[i]-stk[k];
                            stk[k]=height[i];
                        }
                        stk.push_back(height[i]);
                        break;
                    }
                }
            }
        }
        return res;
    }
};