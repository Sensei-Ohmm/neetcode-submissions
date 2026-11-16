class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxlength = 0;
        int count[26] = {false};
        int maxfreq = 0;

        for(int right = 0; right < s.size(); right++){
            count[s[right] - 'A']++;
            maxfreq = max( count[s[right] - 'A'], maxfreq);

            while( right + 1 - left - maxfreq > k){
                count[s[left] - 'A']--;
                left++;
            }

            maxlength = max( right + 1 - left, maxlength);
        }

        return maxlength;
    }
};
