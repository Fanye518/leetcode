// Put each number in its right place.
// For example:
// When we find 5, then swap it with A[4].

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int res = 1;
        // sort(nums.begin(),nums.end());
        // for(auto &num:nums){
        //     if(num>res)return res;
        //     if(num == res)res++;
        // }
        // return res;
        
        for(int i=0;i<nums.size();i++){
            while(nums[i]>0 && nums[i]!=i+1 && nums[i]<nums.size() && nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        
        for(auto & num:nums)
            cout<<num;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)return i+1;
        }
        return nums.size()+1;
    }
};