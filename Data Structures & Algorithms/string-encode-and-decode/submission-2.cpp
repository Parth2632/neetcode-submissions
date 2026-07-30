class Solution {
public:
    string encode(vector<string>& strs) {
        string s = "";
        for(int i=0;i<strs.size();i++){
            s+= to_string(strs[i].size()) + "#" + strs[i];
        }
        return s;
    }
    
    vector<string> decode(string s) {
        vector<string>ans;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            j++;
            ans.push_back(s.substr(j,len)); //start from this index from this length
            i = j+len;
        }
        return ans;
    }
};
