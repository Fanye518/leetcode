class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        if(!nums1.size()||!nums2.size())return res;
        int n1 = nums1.size(), n2= nums2.size();
        auto cmp = [&](auto& p1, auto&p2){
            return nums1[p1.first]+nums2[p1.second]>nums1[p2.first]+nums2[p2.second];
        };
        priority_queue<pair<int, int>,vector<pair<int, int>>,decltype(cmp)> pq(cmp);
        pq.push({0,0});
        unordered_set<string> s;
        s.insert(to_string(0)+"#"+to_string(0));
        while(k--&&pq.size()){
            pair<int, int> pos = pq.top(); pq.pop();
            res.push_back({nums1[pos.first],nums2[pos.second]});
            
            if(pos.first<n1-1){
                string key = to_string(pos.first+1)+"#"+to_string(pos.second);
                if(s.find(key)==s.end())pq.push({pos.first+1,pos.second}), s.insert(key);
                // else cout<<key<<endl;
            }
            if(pos.second<n2-1){
                string key = to_string(pos.first)+"#"+to_string(pos.second+1);
                if(s.find(key)==s.end())pq.push({pos.first,pos.second+1}), s.insert(key);
                // else cout<<key<<endl;
            }
            
            
        }
        
        return res;
    }
};