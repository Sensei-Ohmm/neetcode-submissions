class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int done[128] = {false};

        int left = 0;
        int longest_length = 0;
        int length = 0;

        for(int right = 0; right < s.size(); right++){
            while(done[s[right]]){
                done[s[left]] = false;
                length--;
                left++;
            }

            done[s[right]] = true;
            length++;
            longest_length = max(longest_length, length);
        }
        
        return longest_length;
    }
};
