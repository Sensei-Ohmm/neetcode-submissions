class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out(nums.size());
        vector<int> left(nums.size()+2);
        vector<int> right(nums.size()+2);
        left[0] = 1;
        left[nums.size()+1] = 1;
        right[0] = 1;
        right[nums.size()+1] = 1;

        int mul = 1;
        for( int i = 1; i <= nums.size(); i++){
            left[i] = left[i-1] * nums[i-1];
        }

        for( int i = nums.size(); i >= 1; i--){
            right[i] = right[i+1] * nums[i-1];
        }

        for ( int i = 0; i < nums.size(); i++){
            out[i] = left[i]*right[i+2];
        }

        return out;
    }
};
