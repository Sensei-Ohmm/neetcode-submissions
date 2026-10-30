class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> count;
        vector<pair<int,int>> vec;
        vector<int> output;

        for(int num : nums)
            count[num]++;

        for(auto& [key,val] : count)
            vec.emplace_back(val,key);
        
        sort(vec.rbegin(), vec.rend());

        for( int i = 0; i < k; i++)
            output.emplace_back( vec[i].second);

        return output; 
    }
};
