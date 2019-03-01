//BFS
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        if(!m)return 0;
        int n=grid[0].size();
        queue<pair<int,int>> q;
        vector<int> dirc = {0,-1,0,1,0};
        int num=0;
        vector<vector<vector<bool>>> visited(m,vector<vector<bool>>(n,vector<bool>(64,0)));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){
                    q.push(pair<int,int>(i*n+j,0));
                    visited[i][j][0]=1;
                }
                if(grid[i][j]>='a' && grid[i][j]<='f')num++;
            }
        }
        int count = 0;
        while(q.size()){
            int qsize = q.size();
            for(int i=0;i<qsize;i++){
                int x = q.front().first/n, y = q.front().first%n;
                int keys = q.front().second;
                q.pop();

            
                if(keys==((1<<num)-1))return count;
                

                for(int j =0;j<4;j++){
                    int keys_new = keys;
                    int a = x+dirc[j];
                    int b = y+dirc[j+1];
                    if(a>=m || a<0 || b>=n || b<0 || grid[a][b]=='#')continue;
                    else if(grid[a][b]>='A' && grid[a][b]<='F'){
                        if(!(keys&(1<<(grid[a][b]-'A'))))continue;
                    }
                    else if(grid[a][b]>='a' && grid[a][b]<='f') keys_new=keys|(1<<(grid[a][b]-'a'));
                    
                    if(!visited[a][b][keys]){
                        visited[a][b][keys]=1;
                        q.push(pair<int,int>(a*n+b,keys_new));
                    }
                        
                }
            }
            count++;
        }
        return -1;
        
    }
};