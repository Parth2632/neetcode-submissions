class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>m;
        int left = 0;
        int len = 0;
        int maxfreq = 0;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
            maxfreq = max(maxfreq,m[s[i]]);
            while((i-left+1)-maxfreq > k){
                m[s[left]]--;
                left++;
            }
            len = max(len, i-left+1);
        }
        return len;
    }
};
