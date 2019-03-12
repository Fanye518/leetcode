class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(!grid.size()||!grid[0].size())return 0;
        int n = grid.size(), m = grid[0].size();
        vector<int> memory = vector<int>(m,-1);
        int res = 0;
        for(int i=0;i<n;i++){
            int sum = -1;
            for(int j=0;j<m;j++){
                if(grid[i][j] == 'W'){
                    memory[j] = -1;
                    sum = -1;
                    continue;
                }
                if(grid[i][j] == '0'){
                    if(sum == -1){
                        sum = 0;
                        for(int k= j+1; k<m;k++){
                            if(grid[i][k] == 'W')break;
                            if(grid[i][k] == 'E')sum++;
                        }
                        for(int k= j-1; k>=0;k--){
                            if(grid[i][k] == 'W')break;
                            if(grid[i][k] == 'E')sum++;
                        }
                    }
                    if(memory[j] == -1){
                        memory[j] = 0;
                        for(int k = i+1; k<n; k++){
                            if(grid[k][j] == 'W')break;
                            if(grid[k][j] == 'E')memory[j]++;
                        }
                        for(int k = i-1; k>=0; k--){
                            if(grid[k][j] == 'W')break;
                            if(grid[k][j] == 'E')memory[j]++;
                        }
                    }
                    res = max(res, sum+memory[j]);
                }
            }
        }
        return res;
    }
};