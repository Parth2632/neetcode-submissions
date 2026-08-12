class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> freq;

        for(auto &task : tasks){
            freq[task]++;
        }

        // max heap -> (frequency, task)
        priority_queue<pair<int,char>> pq;

        for(auto &t : freq){
            pq.push({t.second, t.first});
        }

        // cooldown queue -> ((remaining frequency, task), available time)
        queue<pair<pair<int,char>, int>> q;

        int clock = 0;

        while(!pq.empty() || !q.empty()) {

            clock++;

            // BUG YOU HAD:
            // You were doing q.front() without checking if q was empty.
            // q can be empty while pq still has available tasks.
            if(!q.empty() && q.front().second == clock){

                // Task finished cooldown, make it available again
                pq.push(q.front().first);
                q.pop();
            }


            // Execute the task with highest frequency
            if(!pq.empty()){

                auto curr = pq.top();
                pq.pop();

                // We used one occurrence of this task
                curr.first--;


                // BUG YOU HAD:
                // You were putting every task into cooldown.
                // If frequency becomes 0, the task is finished.
                if(curr.first > 0){

                    // BUG YOU HAD:
                    // You used clock instead of clock+n+1.
                    // If executed at time 1 with n=2,
                    // it can return only at time 4.
                    q.push({curr, clock + n + 1});
                }
            }

            // If pq is empty but q has tasks,
            // this clock cycle is an idle period.
        }

        return clock;
    }
};