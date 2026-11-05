class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0;
        int index2 = numbers.size() - 1;
        int sum = numbers[index1] + numbers[index2];
        
        while( sum != target){
            if( sum < target)
                index1++;

            if( sum > target)
                index2--;
            
            sum = numbers[index1] + numbers[index2];
        }

        vector<int> out = {index1 + 1, index2 + 1};
        return out;
    }
};
