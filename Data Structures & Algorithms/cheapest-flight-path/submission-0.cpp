class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto flight: flights){
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            adj[from].push_back({to,price});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}}); //stops,src,cost
        vector<int>dist(n,INT_MAX);
        while(!q.empty()){
            auto [stops,info] = q.front();
            q.pop();
            int city = info.first;
            int cost = info.second;
            if(stops == k+1){
                continue;
            }
            for(auto [nextCity,price]: adj[city]){
                int newCost = cost + price;
                if(newCost < dist[nextCity]){
                    dist[nextCity] = newCost;
                    q.push({stops+1,{nextCity,newCost}});
                }
            }
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};