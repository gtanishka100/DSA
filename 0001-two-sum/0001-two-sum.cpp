class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int> mpp;
       int n = nums.size();
       for(int i=0;i<n;i++){
       int num=nums[i];
       int need= target-num;
       if(mpp.find(need)!=mpp.end()) return {mpp[need],i};
       else mpp[num]=i;
       }
       return {};
    }
};