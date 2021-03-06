class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,int> degree;
        // degree['c']++;
        // if(degree.find('c')!=degree.end())cout<<degree['c']<<endl;
        for(auto &word:words){
            for(auto &c:word){
                degree[c]=0;
            }
        }
        
        unordered_map<char,unordered_set<char>> graph;
        for(int i=0;i<words.size()-1;i++){
            for(int j=0;j<min(words[i].length(),words[i+1].length());j++){
                if(words[i][j]!=words[i+1][j]){
                    graph[words[i][j]].insert(words[i+1][j]);
                    break;
                }
            }
        }
        
        for(auto &a:graph){
            for(auto &b:a.second){
                degree[b]++;
            }
        }
        
        string res = "";
        queue<char>q;
        for(auto &p:degree) if(p.second==0)
            q.push(p.first);
        if(!q.size())return res;
        while(q.size()){
            int qsize = q.size();
            for(int i=0;i<qsize;i++){
                char ch=q.front();q.pop();
                res+=ch;
                for(auto &c:graph[ch]){
                    degree[c]--;
                    if(!degree[c])q.push(c);
                }
                degree.erase(ch);    
            }
        }
        if(degree.size())return "";
        
        // while(degree.size()){
        //     // int n=degree.size();
        //     bool b_find = false;
        //     char ch;
        //     for(auto &p:degree){
        //         if(p.second==0){
        //             b_find = true;
        //             ch = p.first;
        //             res +=ch;
        //             for(auto &c:graph[ch]){
        //                 degree[c]--;
        //             }
        //             degree.erase(ch);
        //             break;
        //         }
        //     }
        //     if(!b_find)return "";
        // }
        return res;
        
    }
};
