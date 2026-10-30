class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> byValue;
        for(int i = 0; i < nums.size(); i++){

            int need = target - nums[i];
            if (byValue.contains(need)){
                return {byValue[need],i};
            }
            
            byValue[nums[i]] = i;
        }
        

        return{};
    }
};
