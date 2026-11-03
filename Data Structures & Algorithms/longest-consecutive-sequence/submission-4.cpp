class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 0) return 0;
        unordered_set<int> nums_set;

        for( int num : nums){
            nums_set.insert(num);
        }

        int highest_length = 0;
        for( int num : nums_set){

            if( nums_set.contains(num - 1))
                continue;

            int length = 0;
            while( nums_set.contains(num)){
                length++;
                num++;
            }

            if( length > highest_length)
                highest_length = length;

        }

       return highest_length;
    }
};
