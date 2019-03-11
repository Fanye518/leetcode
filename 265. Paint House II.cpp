// class Solution {
// private: 
//     int m,n;
//     vector<vector<int>> memory;
// public:
//     int minCostHelper(vector<vector<int>>& costs, int curr, int pre_color){
//         if(curr>=m)return 0;
//         if(pre_color!=-1 && memory[curr][pre_color]!=-1)return memory[curr][pre_color];
//         int res = INT_MAX;
//         for(int i=0;i<n;i++){
//             if(i==pre_color)continue;
//             int cost = minCostHelper(costs, curr+1, i) +costs[curr][i];
//             if(cost<res)res=cost;
//         }
//         if(pre_color!=-1)
//             memory[curr][pre_color] = res;
//         return res;
        
//     }
//     int minCostII(vector<vector<int>>& costs) {
//         if(!costs.size()||!costs[0].size())return 0;
//         m = costs.size();
//         n = costs[0].size();
//         memory = vector<vector<int>>(m,vector<int>(n,-1));
//         return minCostHelper(costs, 0, -1);
//     }
// };

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(!costs.size()||!costs[0].size())return 0;
        int n = costs.size();
        int k = costs[0].size();
        for(int i=1;i<n;i++){
            costs[i][0] +=*min_element(costs[i-1].begin()+1,costs[i-1].end()); 
            costs[i][k-1] +=*min_element(costs[i-1].begin(),costs[i-1].end()-1); 
            for(int j=1;j<k-1;j++){
                costs[i][j] += min(*min_element(costs[i-1].begin(),costs[i-1].begin()+j),*min_element(costs[i-1].begin()+j+1,costs[i-1].end()));
            }
        }
        return *min_element(costs[n-1].begin(),costs[n-1].end());
    }
};
