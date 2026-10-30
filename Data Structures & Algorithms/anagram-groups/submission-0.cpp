class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        unordered_map< string, int> indexer;

        for(int i = 0; i < strs.size(); i++){

            string temp = strs[i];

            sort(temp.begin(), temp.end());

            auto iterator = indexer.find(temp);
            if(iterator != indexer.end()){
                output[iterator->second].emplace_back(strs[i]);
            } else {
                indexer[temp] = output.size();
                output.emplace_back();
                output.back().emplace_back(strs[i]); 
            }
        }

        return output;
    }
};
