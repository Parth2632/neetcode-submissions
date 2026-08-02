class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        int window = s1.length();
        unordered_map<char,int>need;
        unordered_map<char,int>have;
        for(int i=0; i<s1.size(); i++){
            need[s1[i]]++;
        }
        for(int i=0; i<s2.size(); i++){
            have[s2[i]]++;
            if((i-left+1)>window){
                have[s2[left]]--;
                if(have[s2[left]]==0){
                    have.erase(s2[left]);
                }
                left++;
            }
            if(have==need){
                return true;
            }
        }
        return false;
    }
};
