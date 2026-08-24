class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mp;
        for(auto word: wordList){
            mp[word] = 1;
        }
        if(mp.find(endWord)==mp.end()){
            return 0;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        mp[beginWord] = 0; //visited
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            string word = node.first;
            int step = node.second;
            if(word==endWord){
                return step;
            }
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(mp.find(word)!=mp.end() && mp[word]==1){
                        mp[word]=0;
                        q.push({word,step+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
