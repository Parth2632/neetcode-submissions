class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>f;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0; i<s.size(); i++){
            f[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            f[t[i]]--;
        }
        for(int i=0; i<t.size(); i++){
            if(f[t[i]]!=0){
                return false;
            }
        }
        return true;
    }
};
