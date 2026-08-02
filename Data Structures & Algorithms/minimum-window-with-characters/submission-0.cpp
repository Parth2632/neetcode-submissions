class Solution {

public:

    bool valid(unordered_map<char,int>& have, unordered_map<char,int>& needed){

        for(auto x : needed){
            if(have[x.first] < x.second)
                return false;
        }

        return true;
    }


    string minWindow(string s, string t) {

        unordered_map<char,int>have;
        unordered_map<char,int>needed;

        for(char c : t){
            needed[c]++;
        }

        int low = 0;
        int len = 0;
        int start = 0;
        int res = INT_MAX;


        for(int high = 0; high < s.size(); high++){

            have[s[high]]++;

            while(valid(have,needed)){

                len = high-low+1;

                if(len < res){
                    res = len;
                    start = low;
                }

                have[s[low]]--;
                low++;
            }
        }


        if(res == INT_MAX)
            return "";

        return s.substr(start,res);
    }
};
