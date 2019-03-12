class Solution {
public:
    double mincostToHireWorkers(vector<int> q, vector<int> w, int K) {
        if(!q.size())return 0;
        vector<vector<double>> workers;
        for(int i=0;i<q.size();i++)
            workers.push_back({ (double)w[i]/q[i], q[i] });
        sort(workers.begin(),workers.end());
        priority_queue<int> pq;
        double res = DBL_MAX, sum = 0;
        for(auto& worker:workers){
            if(pq.size()==K && worker[1]>=pq.top())continue;
            pq.push(worker[1]), sum+=worker[1];
            if(pq.size()>K)sum-=pq.top(),pq.pop();
            if(pq.size()==K)res = min(res, worker[0]*sum);
        }
        return res;
    }
};