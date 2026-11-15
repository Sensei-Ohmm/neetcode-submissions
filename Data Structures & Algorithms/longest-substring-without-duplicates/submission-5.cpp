class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> done;

        int left = 0;
        int longest_length = 0;
        int length = 0;

        for(int right = 0; right < s.size(); right++){
            while(done.contains(s[right])){
                done.erase(s[left]);
                length--;
                left++;
            }

            done.insert(s[right]);
            length++;
            longest_length = max(longest_length, length);
        }
        
        return longest_length;
    }
};
