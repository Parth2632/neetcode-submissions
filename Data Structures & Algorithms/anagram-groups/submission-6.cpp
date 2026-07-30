class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>f;
        for(int i=0; i<strs.size(); i++){
            string key = strs[i];
            sort(key.begin(),key.end());
            f[key].push_back(strs[i]);
        }
        vector<vector<string>>result;
        for(auto it = f.begin(); it!=f.end(); it++){
            result.push_back(it->second);
        }
        return result;
    }
};
