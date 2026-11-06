class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> out = {};

        int i = 0, j, k, last_i;
        while(i < nums.size()){
            if (i > 0 && nums[i - 1] == nums[i]) {
                i++;
                continue;
            }

            int target = -nums[i];
            j = i + 1;
            k = nums.size() - 1;

            int sum = nums[j] + nums[k];
            while(j < k){

                if( sum == target){    
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    out.emplace_back(triplet);

                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }

                else if(sum < target) j++;

                else if( sum > target) k--;

                sum = nums[j] + nums[k];
            }

            i++;
        }

        return out;
    }
};
