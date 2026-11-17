class Solution {
public:
    bool matches(int s1_count[], int window_count[]) {
        for (int i = 0; i < 26; i++) {
            if (s1_count[i] != window_count[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        int s1_count[26] = {0};
        int window_count[26] = {0};

        // Populate counts for s1 and the initial window in s2
        for (int i = 0; i < s1.length(); i++) {
            s1_count[s1[i] - 'a']++;
            window_count[s2[i] - 'a']++;
        }

        // Slide the fixed window across the rest of s2
        for (int right = s1.length(); right < s2.length(); right++) {
            if (matches(s1_count, window_count)) {
                return true;
            }

            window_count[s2[right] - 'a']++;
            window_count[s2[right - s1.length()] - 'a']--;
        }

        // Check the final window position
        return matches(s1_count, window_count);
    }
};
