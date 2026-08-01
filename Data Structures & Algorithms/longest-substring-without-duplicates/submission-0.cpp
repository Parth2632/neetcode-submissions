class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_map<char,int>m;
        int len = 0;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
            while(m[s[i]]>1){
                m[s[left]]--;
                left++;
            }
            len = max(len,i-left+1);
        }
        return len;
    }
};
