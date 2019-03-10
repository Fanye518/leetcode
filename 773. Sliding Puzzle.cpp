class Solution {
    private:
    int m,n;
public:
    pair<int,int> getZero(vector<vector<int>>& board){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!board[i][j]){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
    int hashFunc(vector<vector<int>>& board){
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res = res<<3 | board[i][j];
            }
        }
        return res;
    }
    vector<vector<int>> revHash(int key){
        vector<vector<int>> res(m,vector<int>(n,0));
        for(int i=m-1;i>-1;i--){
            for(int j=n-1;j>-1;j--){
                res[i][j]=7&key;
                key = key>>3;
            }
        }
        return res;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        if(!board.size()||!board[0].size())return 0;
        m = board.size();
        n = board[0].size();

        unordered_set<int> mark;
        int target = (((((0|1)<<3|2)<<3|3)<<3|4)<<3|5)<<3|0;
        int key = hashFunc(board);
        if(key == target)return 0;
        queue<int> q_board;
        q_board.push(key);
        // queue<pair<int,int>> q_pos;
        // pair<int,int>pos;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(!board[i][j]){
        //             pos={i,j};
        //             goto here;
        //         }
        //     }
        // }
        // here:
        // q_pos.push(pos);
        mark.insert(key);
        
        int qsize=0;
        int count = 0;
        vector<int> dir = {0,1,0,-1,0};
        
        while(qsize=q_board.size()){
            count++;
            for(int i=0;i<qsize;i++){
                // pos = q_pos.front(); q_pos.pop();
                key = q_board.front(); q_board.pop();
                board = revHash(key);
                pair<int,int> pos = getZero(board);
                int x = pos.first, y = pos.second;
                
                for(int k=0;k<4;k++){
                    int a = x+dir[k], b = y+dir[k+1];
                    if(a>-1 && a<m && b>-1 && b<n){
                        vector<vector<int>> new_board(board);
                        swap(new_board[x][y],new_board[a][b]);
                        int new_key = hashFunc(new_board);
                        if(new_key==target)return count;
                        if(mark.find(new_key)!=mark.end())continue;
                        mark.insert(new_key);
                        // q_pos.push({a,b});
                        q_board.push(new_key);
                    }
                }
                
            }
        }
        return -1;
    }
};