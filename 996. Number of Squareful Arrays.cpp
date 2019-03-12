// inline bool squareful(int a){
//     return a == ((int)sqrt(a))*((int)sqrt(a));
// }
class Solution {
    private:
        unordered_map<int,int> degree;
        unordered_map<int,unordered_set<int>> g;
public:
    // int numSquarefulPerms(vector<int> A, int p = -1, int res = 0) {
    //   if (p == A.size() - 1) return 1;
    //   unordered_set<int> s;
    //   for (auto i = p + 1; i < A.size(); ++i) {
    //     if (s.insert(A[i]).second && (p == -1 || pow((int)sqrt(A[i] + A[p]), 2) == A[i] + A[p])) {
    //       swap(A[i], A[p + 1]);
    //       res += numSquarefulPerms(A, p + 1);
    //     }
    //   }
    //   return res;
    // }

    
    int numSquarefulPerms(vector<int>& A) {
        int n = A.size();
        const auto squareful = [](int a){ return a == ((int)sqrt(a))*((int)sqrt(a));};
        for(auto& a:A){
            degree[a]++;
            g[-1].insert(a);
        }
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
            if(squareful(A[i]+A[j])){
                g[A[i]].insert(A[j]);
                g[A[j]].insert(A[i]);
            }
        return helper(A, n, -1);
    }
    
    int helper(vector<int>& A, int pos, int prev){
        if(!(pos--))return 1;
        int res=0;
        for(auto& x:g[prev]){
            if(!degree[x])continue;
            degree[x]--;
            res+=helper(A,pos,x);
            degree[x]++;
        }
        return res;
    }
};