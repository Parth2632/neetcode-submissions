class Twitter {
public:
    Twitter() {
        
    }

    unordered_map<int, vector<pair<int,int>>> freq; 
    unordered_map<int, unordered_set<int>> subs;
    int time = 0;

    void postTweet(int userId, int tweetId) {
        time++;
        freq[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> tweets;

        // Add user's own tweets
        for(auto &tweet : freq[userId]) {
            tweets.push_back(tweet);
        }

        // Add tweets from followed users
        for(auto &sub : subs[userId]) {
            for(auto &tweet : freq[sub]) {
                tweets.push_back(tweet);
            }
        }

        // Min heap to keep latest 10 tweets
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto &tweet : tweets) {
            pq.push(tweet);

            if(pq.size() > 10) {
                pq.pop(); // remove oldest tweet
            }
        }

        vector<int> ans;

        // Extract tweets from newest to oldest
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            subs[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        subs[followerId].erase(followeeId);
    }
};