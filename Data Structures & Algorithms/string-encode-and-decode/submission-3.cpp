class Solution {
public:

    string encode(vector<string>& strs) {
        string out = "";
        for(string s : strs){
            out += s + "@-"; 
        }
        return out;
    }

    vector<string> decode(string s) {
        int from = 0;
        int length = 0;
        vector<string> out;
        for(int i = 0; i < s.size(); i++){
            if( s[i] == '@' && s[i+1] == '-'){
                out.emplace_back(s.substr(from,length));
                i += 1;
                from = i + 1;
                length = 0;
            } else {
                length++;
            }
        }

        return out;
    }
};
