class MedianFinder {
public:
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxi.empty() || num <= maxi.top()){
            maxi.push(num);
        }
        else{
            mini.push(num);
        }

        if(maxi.size()> mini.size() + 1){
            mini.push(maxi.top());
            maxi.pop();
        }
        if(mini.size()> maxi.size() + 1){
            maxi.push(mini.top());
            mini.pop();
        }
    }
    
    double findMedian() {
        if(maxi.size()>mini.size()){
            return maxi.top();
        }
        if(mini.size()>maxi.size()){
            return mini.top();
        }

        return (mini.top()+maxi.top())/2.0;
    }
};
