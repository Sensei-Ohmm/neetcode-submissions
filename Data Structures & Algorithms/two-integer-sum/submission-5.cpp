class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> byValue;
        byValue.reserve(nums.size());
        for(int i = 0; i < nums.size(); i++){

            int need = target - nums[i];
            auto it = byValue.find(need);
            if (it != byValue.end()) {
                return {it->second, i};
            }
            
            byValue[nums[i]] = i;
        }
        

        return{};
    }
};
