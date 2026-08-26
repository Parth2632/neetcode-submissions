class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int x = node.second.first;
            int y = node.second.second;
            if(visited[x][y]){
                continue;
            }
            visited[x][y] = true;
            if(x==n-1 && y==n-1){
                return node.first;
            }
            for(int k=0; k<4; k++){
                int nx  = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < n &&
                    ny >= 0 && ny < n &&
                    !visited[nx][ny]){
                        int newTime = max(node.first,grid[nx][ny]);
                        pq.push({newTime,{nx,ny}});
                    }
            }
        }
        return -1;
    }
};
